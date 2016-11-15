/*Given two arrays, write a function to compute their intersection.
 *
 *Example:
 *Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 *Note:
 *Each element in the result should appear as many times as it shows in both arrays.
 *The result can be in any order.
 *Follow up:
 *What if the given array is already sorted? How would you optimize your algorithm?
 *What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty()||nums2.empty())
            return ret;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>::iterator it1=nums1.begin();
        vector<int>::iterator it2=nums2.begin();
        while(it1!=nums1.end()&&it2!=nums2.end()){
            if(*it1==*it2){
                ret.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1>*it2){
                it2++;
            }
            else if(*it1<*it2){
                it1++;
            }
        }
        return ret;
    }
};
