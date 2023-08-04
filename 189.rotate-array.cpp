/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
                
        int size = nums.size();

        k %= size;

        if(size == 0 || k <= 0)
        {
            return;
        }

        reverse(nums.begin(), nums.begin()+size-k);
        reverse(nums.begin()+size-k, nums.end());

        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
