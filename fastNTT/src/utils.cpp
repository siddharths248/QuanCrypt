#include "ntt/utils.hpp"
#include <cmath>

unsigned int bitReverse(unsigned int x, unsigned int lgn) {
    unsigned int res = 0;
    for (int i = 0; i < lgn; i++) {
        res <<= 1;
        res |= (x & 1);
        x >>= 1;
    }
    return res;
}

std::vector<int> reorder(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr;
    std::vector<int> right(arr.begin(), arr.begin() + n / 2);
    std::vector<int> left(arr.begin() + n / 2, arr.end());
    std::vector<int> result = reorder(right);
    result.insert(result.end(), reorder(left).begin(), reorder(left).end());
    return result;
}

std::vector<int> pointwiseMultiply(const std::vector<int>& a, const std::vector<int>& b, int q) {
    int n = a.size();
    std::vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = (1LL * a[i] * b[i]) % q;
    return res;
}

std::vector<int> scale(const std::vector<int>& arr, int ninv, int q) {
    std::vector<int> res;
    for (int val : arr)
        res.push_back((1LL * val * ninv) % q);
    return res;
}
