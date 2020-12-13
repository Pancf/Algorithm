//
//  Solution146.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution146.hpp"

LRUCache::LRUCache(int capacity): capacity(capacity)
{
}

int LRUCache::get(int key)
{
    auto it = keyToIndex.find(key);
    if (it != keyToIndex.end()) { // find it
        keyValues.splice(keyValues.begin(), keyValues, it->second);
        return it->second->second;
    }
    return -1;
}

void LRUCache::put(int key, int value)
{
    auto it = keyToIndex.find(key);
    if (it != keyToIndex.end()) {
        it->second->second = value;
        keyValues.splice(keyValues.begin(), keyValues, it->second);
    } else {
        if (keyToIndex.size() >= capacity) {
            int keyToRemove = keyValues.back().first;
            keyToIndex.erase(keyToRemove);
            keyValues.pop_back();
        }
        keyValues.emplace_front(key, value);
        keyToIndex.insert({key, keyValues.begin()});
    }
}
