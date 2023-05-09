/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int left = 0, right = matrix[0].size()-1,
            up = 0, down = matrix.size()-1;

        while(left <= right && up <= down)
        {
            // go right
            for(auto i=left; i<=right; i++)
            {
                ans.push_back(matrix[up][i]);
            }        
            up++;

            // go down
            for(auto i=up; i<=down; i++)
            {
                ans.push_back(matrix[i][right]);
            }        
            right--;

            // go left
            if(up <= down)
            {
                for(auto i=right; i>=left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            // go up
            if(left <= right)
            {
                for(auto i=down; i>=up; i--)
                {
                    ans.push_back(matrix[i][left]);
                }            
                left++;
            }
        }

        return ans;
    }
};
// @lc code=end

