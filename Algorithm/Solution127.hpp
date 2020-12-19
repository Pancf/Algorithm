//
//  Solution127.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/19.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution127_hpp
#define Solution127_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Solution127 {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
    static void test()
    {
        std::string beginWord{"hit"};
        std::string endWord{"cog"};
        std::vector<std::string> wordList{"hot","dot","dog","lot","log"};
        Solution127 s;
        printf("%d\n", s.ladderLength(beginWord, endWord, wordList));
    }
};

#endif /* Solution127_hpp */
