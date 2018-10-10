Question: Two Sum

Description:

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```





Solution:

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * 直接暴力两轮遍历，复杂度o(n2)；因为C 没有现成的map可用，就暴力了一些。其实也可以一轮遍历，每 
 * 次loop从<nums[i], i> 形式的map中找结果，找不到就塞进map，其实是拿map的空间换了暴力解法第二
 * 轮遍历的时间。
*/
int* twoSum(int* nums, int numsSize, int target) {
    int* res = (int*)malloc(sizeof(int) * 2); 
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (target - nums[i] == nums[j]) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}
```

