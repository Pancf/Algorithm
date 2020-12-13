//
//  Solution460.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution460.hpp"

// access count plus 1 and update access time for item
void LFUCache::reorderList(Item &itemRef)
{
    auto freqIt = itemRef.freqIt;
    auto timeIt = itemRef.timeIt;
    
    if (freqIt != freqList.begin()) { // 非表头
        auto prev = freqIt;
        prev--;
        if (prev->first == (freqIt->first + 1)) { //追加在prev的表头
            prev->second.splice(prev->second.begin(), freqIt->second, timeIt);
            itemRef.freqIt = prev;
            itemRef.timeIt = prev->second.begin();
            if (freqIt->second.size() == 0) {
                freqList.erase(freqIt);
            }
        } else {
            if (freqIt->second.size() == 1) { //同freq的只有这个key-val
                freqIt->first++;
            } else {
                auto newIt = freqList.emplace(freqIt, std::pair<int, std::list<int>>(freqIt->first + 1, {}));
                newIt->second.splice(newIt->second.begin(), freqIt->second, timeIt);
                itemRef.freqIt = newIt;
                itemRef.timeIt = newIt->second.begin();
            }
        }
    } else { //表头
        if (freqList.front().second.size() == 1) { //同freq的只有这个key-val
            freqList.front().first++;
        } else {
            auto freq = freqList.front().first;
            std::list<int> tmp;
            tmp.splice(tmp.begin(), freqList.front().second, timeIt);
            freqList.emplace_front(std::pair<int, std::list<int>>(freq+1,tmp));
            itemRef.freqIt = freqList.begin();
            itemRef.timeIt = freqList.front().second.begin();
        }
    }
}

int LFUCache::get(int key)
{
    auto it = mp.find(key);
    if (it != mp.end()) {
        auto val = it->second.val;
        reorderList(it->second);
        return val;
    }
    return -1;
}

void LFUCache::put(int key, int value)
{
    if (capacity == 0) return;
    auto it = mp.find(key);
    if (it != mp.end()) { // find key
        it->second.val = value;
        reorderList(it->second);
    } else {
        auto *onceList = &(freqList.back().second);
        if (mp.size() == capacity) { // erase
            if (onceList->size() > 0) {
                mp.erase(onceList->back());
                onceList->pop_back();
            }
        }
        if (freqList.back().first != 1) { // insert once list
            freqList.emplace_back(std::pair<int, std::list<int>>(1, {}));
            onceList = &(freqList.back().second);
        }
        onceList->emplace_front(key);
        Item item;
        item.val = value;
        item.freqIt = freqList.end();
        item.freqIt--;
        item.timeIt = onceList->begin();
        mp[key] = item;
    }
}
