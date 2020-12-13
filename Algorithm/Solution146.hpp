//
//  Solution146.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution146_hpp
#define Solution146_hpp

#include <stdio.h>
#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity);
    // implement get and put in o(1)
    int get(int key);
    void put(int key, int value);

private:
    using KeyValueT = std::list<std::pair<int, int>>;
    std::unordered_map<int, KeyValueT::iterator> keyToIndex;
    KeyValueT keyValues;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif /* Solution146_hpp */
