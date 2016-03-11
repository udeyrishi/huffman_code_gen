#include "HuffmanCode.hpp"
#include "DoubleUtils.hpp"
#include <unordered_map>
#include <iostream>
#include <string>

const long DOUBLE_ERR_FACTOR = 1.0e12;
using namespace std;

bool checkValidPmf(const unordered_map<string, double> &pmf);

int main(int argc, char **argv) {
    if (argc < 2 || argc % 2 == 0) {
        cerr << "Usage: " << argv[0] << " <symbol1> <prob1> <symbol2> <prob2> ..." << endl;
        return -1;
    }

    unordered_map<string, double> pmf;
    for (int i = 1; i < argc; i += 2) {
        pmf[argv[i]] = stod(argv[i+1]);
    }

    if (!checkValidPmf(pmf)) {
        cout << "Sum of all the probabilities in the PMF should be 1" << endl;
        return -1;
    }

    HuffmanCode huffmanCode(pmf);
    cout << huffmanCode;
    return 0;
}

bool checkValidPmf(const unordered_map<string, double> &pmf) {
    double sumProbabilities = 0.0;
    for (const auto &probability : pmf) {
        sumProbabilities += probability.second;
    }

    return DoubleUtils::areNearlyEqual(sumProbabilities, 1.0, DOUBLE_ERR_FACTOR);
}
