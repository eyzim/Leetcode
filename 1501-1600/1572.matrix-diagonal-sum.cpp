/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int ans = 0;
        int s = mat.size()-1;

        for(auto i=0; i<mat.size(); i++)
        {
            ans += mat[i][i];
            ans += mat[i][s-i];
        }

        if(s%2 == 0)
        {
            ans -= mat[s/2][s/2];
        }

        return ans;
    }
};
// @lc code=end
