/*
 * @lc app=leetcode id=1837 lang=cpp
 *
 * [1837] Sum of Digits in Base K
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the sum of the digits in base k.
 *
 * The Solution class provides a method, sumBase, that takes an integer n and an
 * integer k as input and returns the sum of the digits of n in base k.
 * The method calculates the sum of the digits by dividing the number by k and
 * adding the remainder.
 * - 12 / 2 = 6 ... 0 ↑ => 1100(2)
 * -  6 / 2 = 3 ... 0 |
 * -  3 / 2 = 1 ... 1 |
 * -  1 / 2 = 0 ... 1 |
 *
 * Algorithm Complexity:
 * - The time complexity of the method is O(log(n)), where n is the input
 * integer.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int sumBase(int n, int k) {
		int ans = 0;
		while (n) {
			ans += n % k;
			n = floor(n / k);
		}

		return ans;
	}
};
// @lc code=end
