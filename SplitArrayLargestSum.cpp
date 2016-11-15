/*Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. 
 *Write an algorithm to minimize the largest sum among these m subarrays.
 *
 *Note:
 *Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.
 *Examples:
 *
 *Input:
 *nums = [7,2,5,10,8]
 *m = 2

 *Output:
 *18

 *Explanation:
 *There are four ways to split nums into two subarrays.
 *The best way is to split it into [7,2,5] and [10,8],
 *where the largest sum among the two subarrays is only 18.
*/

class Solution {
public:
    bool canSplit(vector<int>& nums,int cut,long long max){
        int accumulate=0;
        for(auto num:nums){
            if((accumulate+num)<=max)
                accumulate+=num;
            else{
                cut--;
                accumulate=num;
                if(cut<0) return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long right=0,left=0;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            left=max(left,(long long)*it);
            right+=*it;
        }
        while(left<right){
            long long mid=(left+right)/2;
            if(canSplit(nums,m-1,mid)) right=mid;
            else left=mid+1;
        }
        return left;
    }
};
