/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        
        if(c.size() == 2) return 1;

        int a = c[1][0] - c[0][0], b = c[1][1] - c[0][1];

        for(auto i=1; i<c.size(); i++)
        {
            if(b * (c[i][0] - c[i-1][0]) != a * (c[i][1] - c[i-1][1]))
            {
                return 0;
            }
        }

        return 1;
    }
};
// @lc code=end

