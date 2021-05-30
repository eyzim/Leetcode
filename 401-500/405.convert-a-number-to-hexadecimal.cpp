/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

/*
Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
*/

// @lc code=start
class Solution {
public:
    string toHex(int num) {

        if(num == 0)    return "0";
        
        uint32_t n = static_cast<uint32_t>(num);
        char toH[17] = "0123456789abcdef";

        string ans = "";

        while(n)
        {
            ans = toH[n & 0xF] + ans;
            n >>= 4;
        }

        return ans;
    }
};
// @lc code=end

