/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {

        auto ans = 1;

        for(auto i:nums)
        {
            if(i==0)
            {
                return 0;
            }

            if(i<0)
            {
                ans *= (-1);
            }
        }

        return ans;
    }
};
// @lc code=end

