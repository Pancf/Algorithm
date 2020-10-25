//
//  Solution49.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution49.hpp"
#include <algorithm>
#include <map>

std::vector<std::vector<std::string>> Solution49::groupAnagrams(std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> res;
    if (strs.size() == 0) return res;
    std::map<std::string, std::vector<std::string>> dict;
    for (auto str : strs) {
        auto copyStr{str};
        std::sort(copyStr.begin(), copyStr.end());
        if (dict.find(copyStr) == dict.end()) {
            // not found
            std::vector<std::string> v{str};
            dict[copyStr] = v;
        } else {
            auto& v = dict[copyStr];
            v.push_back(str);
        }
    }
    for (auto pair : dict) {
        res.push_back(pair.second);
    }
    return res;
}
