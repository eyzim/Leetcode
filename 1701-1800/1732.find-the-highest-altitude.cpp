/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int ans = 0, gainNow = 0;

        for(auto i:gain)
        {
            gainNow += i;
            ans = max(ans, gainNow);
        }

        return ans;
    }
};
// @lc code=end

