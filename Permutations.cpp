/*Given a collection of distinct numbers, return all possible permutations.
 *
 *For example,
 *[1,2,3] have the following permutations:
 *[
 * [1,2,3],
 * [1,3,2],
 * [2,1,3],
 * [2,3,1],
 * [3,1,2],
 * [3,2,1]
 *]
 */
 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do
        {
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return result;
    }
};
