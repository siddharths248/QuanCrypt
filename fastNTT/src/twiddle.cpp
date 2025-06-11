#include "ntt/twiddle.hpp"
#include "ntt/utils.hpp"
#include "ntt/mod_ops.hpp"
#include <cmath>

std::vector<int> computePsiPowers(int psi, int n, int q) {
    std::vector<int> powers(n);
    for (int i = 0; i < n; i++)
        powers[i] = mod_pow(psi, i, q);

    int lgn = std::log2(n);
    std::vector<int> psi_br(n);
    for (int k = 0; k < n; k++) {
        int rev_k = bitReverse(k, lgn);
        psi_br[rev_k] = powers[k];
    }
    return psi_br;
}

std::vector<int> computePsiInvPowers(int psi_inv, int n, int q) {
    return computePsiPowers(psi_inv, n, q);  // Identical logic
}


