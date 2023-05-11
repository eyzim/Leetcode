/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start

/*
一個正整數的質因數只包含 2、3 或 5 的話就是 "Ugly number"
另外，1 會被判定為 "Ugly number"
*/

class Solution {
public:
    bool isUgly(int n) {
        
        if(n < 1)    return false;
        if(n == 1)  return true;

        // 扣除 2 的次方
        while(n%2==0)
        {
            n /= 2;
        }
        // 扣除 3 的次方
        while(n%3==0)
        {
            n /= 3;
        }
        // 扣除 5 的次方
        while(n%5==0)
        {
            n /= 5;
        }

        // 只剩自己，表示質因數只包含 2, 3, 5
        return n==1;
    }
};
// @lc code=end

