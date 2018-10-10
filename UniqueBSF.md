Question: Unique Binary Search Trees

Description: 

Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?

**Example:**

```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



Analysis：

给定1…n，要构建BST，假设以i 作为根节点，F(i, n) 表示以i 为根节点的条件下一共有多少种结果，H(n) 表示给定n，一共有多少种结果。可以得到一个简单的公式，即$H(n) = \sum_{i=1}^{n}F(i, n)$ 。  

问题就转变成了怎么求F(i, n)。因为以i 为根节点的时候，[1, ..., i-1] 和[i+1, ..., n] 分别是根节点的左右子树，而[i+1, ..., n] 的种类其实和[1, n-i] 是一样的，所以F(i, n) = H(i-1) * H(n-i) 。

综上可得 $H(n) = \sum_{i=1}^{n}H(i-1) * H(n-i)​$ 。



Solution：

```c
int numTrees(int n) {
    int* ret = (int*)malloc(sizeof(int) * (n+1));
    ret[0] = 1;
    ret[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            ret[i] += ret[j - 1] * ret[i - j];
        }
    }
    return ret[n];
}
```

