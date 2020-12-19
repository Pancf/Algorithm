//
//  Solution208.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/19.
//  

#ifndef Solution208_hpp
#define Solution208_hpp

#include <stdio.h>
#include <string>

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word);
    
    /** Returns if the word is in the trie. */
    bool search(std::string word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix);
    
private:
    struct TrieNode {
        bool isEnd;
        TrieNode *links[26];
        TrieNode(): isEnd(false) {
            for (int i = 0; i < 26; ++i) links[i] = nullptr;
        }
    };
    TrieNode *root;
};

#endif /* Solution208_hpp */
