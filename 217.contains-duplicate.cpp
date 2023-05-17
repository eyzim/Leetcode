/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i:nums)
        {
            // if the number exists already
            if(mp[i])
            {
                return true;
            }

            mp[i]++;
        }

        return false;
    }
};
// @lc code=end

