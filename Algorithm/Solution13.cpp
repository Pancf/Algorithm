//
//  Solution13.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution13.hpp"

int Solution13::romanToInt(std::string s)
{
    // I -> 1
    // V -> 5
    // X -> 10
    // L -> 50
    // C -> 100
    // D -> 500
    // M -> 1000
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case 'M':
                res += 1000;
                break;
            case 'D':
                res += 500;
                break;
            case 'C':
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'D') {
                        res += 400;
                        i += 1;
                    } else if (s[i + 1] == 'M') {
                        res += 900;
                        i += 1;
                    } else {
                        res += 100;
                    }
                } else {
                    res += 100;
                }
                break;
            case 'L':
                res += 50;
                break;
            case 'X':
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'L') {
                        res += 40;
                        i += 1;
                    } else if (s[i + 1] == 'C') {
                        res += 90;
                        i += 1;
                    } else {
                        res += 10;
                    }
                } else {
                    res += 10;
                }
                break;
            case 'V':
                res += 5;
                break;
            case 'I':
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'V') {
                        res += 4;
                        i += 1;
                    } else if (s[i + 1] == 'X') {
                        res += 9;
                        i += 1;
                    } else {
                        res += 1;
                    }
                } else {
                    res += 1;
                }
                break;
        }
    }
    return res;
}
