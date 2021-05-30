/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()<3)
        {
            return nums.size();
        }

        for(auto i=2; i<nums.size(); i++) {
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }

        return nums.size();
    }
};
// @lc code=end
