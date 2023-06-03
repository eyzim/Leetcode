/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;

        for(auto i:nums)
        {
            // if the number exists already
            if(mp.count(i))
            {
                return true;
            }

            // if the number first exist, mark it
            mp.insert(i);
        }

        return false;
    }
};
// @lc code=end

