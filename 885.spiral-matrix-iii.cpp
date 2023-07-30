/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> ans;
        int up = 0, down = rows-1, left = 0, right = cols-1;
        int dir = 0;
        int count = rows * cols;

        // while(ans.size() < count)
        {
            for(auto i=cStart; i<=right; i++)
            {
                ans.push_back({rStart, i});
            }

            for(auto i=)
        }

        return ans;
    }
};
// @lc code=end

