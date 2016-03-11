#include "DoubleUtils.hpp"
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

bool DoubleUtils::areNearlyEqual(double a, double b, double errorFactor) {
    return (a == b || abs(a-b) < abs(min(a, b)) * numeric_limits<double>::epsilon() * errorFactor);
}