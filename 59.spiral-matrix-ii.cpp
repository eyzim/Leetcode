/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<int> col(n, 0);
        vector<vector<int>> ans(n, col);

        int num = 1;
        int left = 0, right = n-1,
            up = 0, down = n-1;

        while(left <= right && up <= down)
        {
            // go right
            for(auto i=left; i<=right; i++)
            {
                ans[up][i] = num++;
            }
            up++;

            // go down
            for(auto i=up; i<=down; i++)
            {
                ans[i][right] = num++;
            }
            right--;

            // go left
            if(up <= down)
            {
                for(auto i=right; i>=left; i--)
                {
                    ans[down][i] = num++;
                }
                down--;
            }

            // go up
            if(left <= right)
            {                
                for(auto i=down; i>=up; i--)
                {
                    ans[i][left] = num++;
                }
                left++;
            }
        }
        
        return ans;
    }
};
// @lc code=end
