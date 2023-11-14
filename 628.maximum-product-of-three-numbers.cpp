/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        if(nums.size()==3)  return nums[0]*nums[1]*nums[2];

        sort(nums.begin(), nums.end());

        int s = nums.size()-1;

        return max(nums[s]*nums[s-1]*nums[s-2], nums[0]*nums[1]*nums[s]);

        // - - +
        // multiply the right most three
    }
};
// @lc code=end

