#include "HuffmanCode.hpp"
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

void usage(string programName) {
    cerr << "Usage: " << programName << " <symbol1> <prob1> <symbol2> <prob2> ..." << endl;
    cerr << "Sum of all probabilities should be near 1 +/- 0.0000005" << endl;
}

int main(int argc, char **argv) {
    if (argc < 2 || argc % 2 == 0) {
        usage(argv[0]);
        return -1;
    }

    unordered_map<string, double> pmf;
    for (int i = 1; i < argc; i += 2) {
        pmf[argv[i]] = stod(argv[i+1]);
    }

    HuffmanCode huffmanCode(pmf);
    cout << huffmanCode << endl;
    return 0;
}