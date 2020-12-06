//
//  Solution116.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution116_hpp
#define Solution116_hpp

#include <stdio.h>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution116 {
public:
    Node* connect(Node* root);
    static void test()
    {
        Node root{1};
        Node node1{2};
        Node node2{3};
        Node node3{4};
        Node node4{5};
        Node node5{6};
        Node node6{7};
        root.left = &node1;
        root.right = &node2;
        node1.left = &node3;
        node1.right = &node4;
        node2.left = &node5;
        node2.right = &node6;
        Solution116 s;
        s.connect(&root);
    }
};

#endif /* Solution116_hpp */
