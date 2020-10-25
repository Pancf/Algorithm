//
//  Solution48.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution48_hpp
#define Solution48_hpp

#include <stdio.h>
#include <vector>

class Solution48 {
public:
    void rotate(std::vector<std::vector<int>>& matrix);
    static void test()
    {
        std::vector<std::vector<int>> input = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        Solution48 s = Solution48();
        s.rotate(input);
    }
};

#endif /* Solution48_hpp */
