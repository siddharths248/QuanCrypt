#include "ntt_forward.hpp"
#include "mod_ops.hpp"
#include "twiddle.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include "ct.hpp"

#include <cmath>
#include <vector>


std::vector<int> forwardNTT(std::vector<int>& arr) {
    int len = arr.size();
    int lgn = std::log2(len);
    std::vector<int> result = arr;
    std::vector<int> psi_powers = computePsiPowers(PSI, len, q);

    int pw_idx = 1;
    for (int s = 1; s <= lgn; s++) {
        int sets = 1 << (s - 1);
        int ops = len >> s;
        int offset = ops;
        int base = 2 * ops;

        for (int set = 0; set < sets; set++) {
            int idx = base * set;
            for (int op = 0; op < ops; op++) {
                auto [u, v] = CT(result[idx], result[idx + offset], psi_powers[pw_idx]);
                result[idx] = u;
                result[idx + offset] = v;
                idx++;
            }
            pw_idx++;
        }
    }
    return result;
}
