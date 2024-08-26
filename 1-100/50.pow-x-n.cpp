/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the value of x raised to the power of n.
 *
 * The Solution class provides a method, myPow, that takes a double x and an
 * integer n as input and returns the value of x raised to the power of n. The
 * method uses a binary exponentiation approach to calculate the result
 * efficiently. It iteratively squares the value of x and divides n by 2 until n
 * becomes 0. The final result is then returned based on the value of n.
 * For example, if x = 2 and n = 5, in the for loop,
 * 1. ans = 1, x = 2, n = 5
 * 2. ans = 2, x = 4, n = 2
 * 3. ans = 2, x = 16, n = 1
 * The final result is 32, which comes from ans *= x (16 * 2).
 *
 * Algorithm Complexity:
 * - The myPow method has a time complexity of O(log n), where n is the value of
 * the exponent.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	double myPow(double x, int n) {
		if (x == 1 || x == 0)
			return x;

		double ans = 1.0;
		int new_n = abs(n);

		while (new_n) {
			if ((new_n & 1) != 0) {
				ans *= x;
			}
			x = x * x;
			new_n /= 2;
		}

		return (n < 0) ? 1 / ans : ans;
	}
};
// @lc code=end
