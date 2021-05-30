/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int c = 0;

        for(auto i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin()+i);
                i--;
                c++;
            }
        }

        for(auto i=0; i<c; i++)
        {
            nums.push_back(0);
        }
    }
};
// @lc code=end