#include "StringUtils.hpp"
#include <cstddef>

using namespace std;

vector<string> StringUtils::split(string str, string delimiter) {
    vector<string> parts;
    size_t last = 0;
    size_t next = 0;
    while ((next = str.find(delimiter, last)) != string::npos) {
        parts.push_back(str.substr(last, next-last));
        last = next + 1;
    }
    parts.push_back(str.substr(last));
    return parts;
}