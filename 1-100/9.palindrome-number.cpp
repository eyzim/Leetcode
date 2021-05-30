/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)   return false;
        else if(x < 10)  return true;

        long int before = x, after = 0;

        while(before > 0)
        {
            after = 10*after + (before % 10);
            before /= 10;
        }

        return x == after;
    }
};
// @lc code=end

