/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)   return 0;

        return log2(n) == (int)(log2(n));
    }
};
// @lc code=end

