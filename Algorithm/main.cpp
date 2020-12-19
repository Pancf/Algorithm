//
//  main.cpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include <iostream>
#include "Solution208.hpp"

int main(int argc, const char * argv[]) {
    Trie trie;
    trie.insert("apple");
    assert(trie.search("apple") == true);   // returns true
    assert(trie.search("app") == false);     // returns false
    assert(trie.startsWith("app") == true); // returns true
    trie.insert("app");
    assert(trie.search("app") == true);
    return 0;
}
