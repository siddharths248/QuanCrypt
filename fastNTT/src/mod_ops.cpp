#include "ntt/mod_ops.hpp"

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp >>= 1;
    }
    return result;
}
