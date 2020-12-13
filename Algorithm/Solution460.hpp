//
//  Solution460.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution460_hpp
#define Solution460_hpp

#include <stdio.h>
#include <unordered_map>
#include <list>

class LFUCache {
public:
    LFUCache(int capacity): capacity(capacity) {
        freqList.emplace_back(std::pair<int, std::list<int>>(1, {}));
    }
    
    int get(int key);
    void put(int key, int value);
    
private:
    
    int capacity;
    
    struct Item {
        int val;
        std::list<std::pair<int, std::list<int>>>::iterator freqIt;
        std::list<int>::iterator timeIt;
    };
    
    std::unordered_map<int, Item> mp;
    // 二维双向链表，第一维按frequency降序，第二维按access time降序
    std::list<std::pair<int, std::list<int>>> freqList;
    
    void reorderList(Item &);
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif /* Solution460_hpp */
