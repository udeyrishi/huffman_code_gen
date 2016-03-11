/**
 Copyright 2016 Udey Rishi
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

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