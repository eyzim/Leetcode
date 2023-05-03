/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans = {{}, {}};

        unordered_set s1(nums1.begin(), nums1.end());
        unordered_set s2(nums2.begin(), nums2.end());

        for(auto x:s1)
        {
            if(!s2.count(x)) ans[0].push_back(x);
        }
        for(auto x:s2)
        {
            if(!s1.count(x)) ans[1].push_back(x);
        }

        return ans;
    }
};
// @lc code=end
