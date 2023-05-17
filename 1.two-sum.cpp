/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(auto i=0; i<nums.size(); i++)
        {
            // if the another answer is existed already
            if(mp[target-nums[i]])
            {
               return {i, mp[target-nums[i]]-1};
            }
            // store the position+1 of myself
            mp[nums[i]] = i+1;
        }

        return {};
    }
};
// @lc code=end

