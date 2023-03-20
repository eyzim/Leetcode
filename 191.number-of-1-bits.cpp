/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        short ans = 0;

        while(n)
        {
            ans++;
            n &= (n-1);
        }
        
        return ans;
    }
};
// @lc code=end

