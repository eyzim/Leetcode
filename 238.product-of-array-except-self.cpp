/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 1);

        int fromStart = 1, fromEnd = 1;

        for(auto i=0; i<nums.size(); i++)
        {
            ans[i] *= fromStart;
            fromStart *= nums[i];
        }

        for(int i=nums.size()-1; i>=0; i--)
        {
            ans[i] *= fromEnd;
            fromEnd *= nums[i];
        }

        return ans;
    }
};
// @lc code=end

