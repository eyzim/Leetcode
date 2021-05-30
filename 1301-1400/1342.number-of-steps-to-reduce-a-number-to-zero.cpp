/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 *
 * @brief The implementation of the Solution class, which is used to find the
 * number of steps to reduce a number to zero.
 *
 * Given a non-negative integer num, return the number of steps to reduce it to
 * zero. If the current number is even, you have to divide it by 2, otherwise,
 * you have to subtract 1 from it.
 *
 * Algorithm Complexity:
 * - The numberOfSteps method has a time complexity of O(logn), where n is the
 * input number.
 * - The space complexity of the numberOfSteps method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int numberOfSteps(int num) {
		int steps = 0;

		while (num) {
			if (num % 2)
				num--;
			else
				num /= 2;
			steps++;
		}

		return steps;
	}
};
// @lc code=end
