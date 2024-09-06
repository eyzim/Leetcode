/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * @brief The implementation of the Solution class, which is used to reverse the
 * digits of an integer.
 *
 * The solution uses a while loop to reverse the digits of the integer. It
 * checks if the reversed integer is within the 32-bit signed integer range. If
 * it is not, it returns 0.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(log(x)), where x is the input
 * integer.
 * - The solution has a space complexity of O(1).
 */

// @lc code=start
class Solution {
   public:
	int reverse(int x) {
		int ans = 0;

		while (x != 0) {
			// Check for overflow before multiplying by 10
			if ((10 * ans > INT_MAX) || (10 * ans < INT_MIN)) {
				return 0;  // Indicates that the reversed integer is not within
						   // the 32-bit signed integer range
			}
			ans = 10 * ans + x % 10;
			x /= 10;
		}

		return ans;
	}
};
// @lc code=end
