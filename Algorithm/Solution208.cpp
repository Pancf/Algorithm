//
//  Solution208.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/19.
//  

#include "Solution208.hpp"

void Trie::insert(std::string word)
{
    TrieNode *cur = root;
    for (auto ch : word) {
        if (cur && cur->links[ch - 'a']) {
            cur = cur->links[ch - 'a'];
        } else {
            TrieNode *node = new TrieNode;
            cur->links[ch - 'a'] = node;
            cur = node;
        }
    }
    cur->isEnd = true;
}

bool Trie::search(std::string word)
{
    TrieNode *cur = root;
    int i = 0;
    for (; i < word.length(); ++i) {
        char ch = word[i];
        if (cur && cur->links[ch - 'a']) {
            cur = cur->links[ch - 'a'];
        } else break;
    }
    return (i == word.size()) && (cur->isEnd || !cur);
}

bool Trie::startsWith(std::string prefix)
{
    TrieNode *cur = root;
    int i = 0;
    for (; i < prefix.length(); ++i) {
        char ch = prefix[i];
        if (cur && cur->links[ch - 'a']) {
            cur = cur->links[ch - 'a'];
        } else break;
    }
    return (i == prefix.size());
}
