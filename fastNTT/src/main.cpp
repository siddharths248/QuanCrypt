#include <iostream>
#include <vector>
#include <chrono>
#include "ntt/ntt_forward.hpp"
#include "ntt/ntt_inverse.hpp"
#include "ntt/utils.hpp"

using namespace std;

const int q = 7681;
const int N = 32;
const int NINV = 7441;

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<int> arr1 = {3193, 6874, 834, 2373, 6222, 6504, 4746, 2099, 2396, 1541, 434, 6788, 5193, 224, 3964, 7313, 2980, 1510, 3194, 2533, 2788, 546, 1256, 1308, 6554, 6419, 4611, 6691, 1038, 538, 3759, 5955};
    vector<int> arr2 = {6830, 1625, 2154, 680, 91, 7021, 6435, 7160, 1916, 7186, 92, 2119, 7461, 2867, 5262, 943, 3748, 6061, 5340, 5991, 6681, 5734, 4034, 4796, 1359, 7379, 5165, 4057, 1500, 1169, 1797, 2327};

    auto ntt1 = forwardNTT(arr1);
    auto ntt2 = forwardNTT(arr2);
    auto prod = pointwiseMultiply(ntt1, ntt2, q);
    auto inttRes = inverseNTT(prod);
    auto result = scale(inttRes, NINV, q);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "time = " << duration.count() << " microseconds" << endl;
    cout << "negative wrapped convolution:" << endl;
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
