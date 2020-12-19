//
//  Solution127.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/19.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution127.hpp"
#include <unordered_set>

int Solution127::ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    // BFS
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    std::unordered_set<std::string> head, tail, *headPtr, *tailPtr;
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    head.insert(beginWord);
    tail.insert(endWord);
    int res = 2;
    while (!head.empty() && !tail.empty()) {
        // ensure we always traversing smaller set
        if (head.size() < tail.size()) {
            headPtr = &head;
            tailPtr = &tail;
        } else {
            headPtr = &tail;
            tailPtr = &head;
        }
        std::unordered_set<std::string> temp;
        for (auto it = headPtr->begin(); it != headPtr->end(); ++it) { // all neighbors
            auto word = *it;
            for (int i = 0; i < word.size(); ++i) {
                auto ch = word[i];
                for (int k = 0; k < 26; k++) { // change one char each iter and find whether can transform
                    word[i] = 'a' + k;
                    if (tailPtr->find(word) != tailPtr->end()) {
                        return res;
                    }
                    if (wordSet.find(word) != wordSet.end()) { // if can transform, this word is the neighbor
                        temp.insert(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        res++;
        headPtr->swap(temp);
    }
    return 0;
}
