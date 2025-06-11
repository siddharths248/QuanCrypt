#include "ntt_inverse.hpp"
#include "mod_ops.hpp"
#include "twiddle.hpp"
#include "gs.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include <cmath>
#include <vector>

std::vector<int> inverseNTT(std::vector<int>& arr) {
    int len = arr.size();
    int lgn = std::log2(len);
    std::vector<int> result = arr;

    std::vector<int> psi_inv_powers = computePsiInvPowers(PSI_INV, len, q);
    std::vector<int> psiInvPowsReordered = reorder(psi_inv_powers);

    int pw_idx = 0;
    for (int s = 1; s <= lgn; s++) {
        int ops = 1 << (s - 1);
        int sets = len >> s;
        int off = ops;
        int base = 2 * ops;

        for (int set = 0; set < sets; set++) {
            int idx = base * set;
            for (int op = 0; op < ops; op++) {
                auto [u, v] = GS(result[idx], result[idx + off], psiInvPowsReordered[pw_idx]);
                result[idx] = u;
                result[idx + off] = v;
                idx++;
            }
            pw_idx++;
        }
    }
    return result;
}
