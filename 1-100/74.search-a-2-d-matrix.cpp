/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int h = matrix.size(), w = matrix[0].size();
        
        if(!h || !w)    return 0;        

        int left = 0, right = h*w-1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int x = mid/w, y = mid%w; 
            
            if(matrix[x][y] == target)
            {
                return 1;
            }
            else if(matrix[x][y] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return 0;
    }
};
// @lc code=end