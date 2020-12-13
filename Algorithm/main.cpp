//
//  main.cpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include <iostream>
#include "Solution146.hpp"

int main(int argc, const char * argv[]) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    auto val = cache.get(1);
    assert(val == 1);
    cache.put(3, 3);
    val = cache.get(2);
    assert(val == -1);
    cache.put(4, 4);
    val = cache.get(1);
    assert(val == -1);
    val = cache.get(3);
    assert(val == 3);
    val = cache.get(4);
    assert(val == 4);
    return 0;
}
