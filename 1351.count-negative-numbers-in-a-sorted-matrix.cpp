/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int ans = 0, m = grid.size(), n = grid[0].size();

        for(auto i=0; i<m; i++)
        {
            for(auto j=0; j<n; j++)
            {
                if(grid[i][j] < 0)
                {
                    ans += (n-j);
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

