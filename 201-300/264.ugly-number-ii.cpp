/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * @brief The implementation of the Solution class, which is used to find the
 * nth ugly number. Note that an ugly number is a positive number whose prime
 * factors only include 2, 3, and 5.
 *
 * The Solution class provides a method, nthUglyNumber, that takes an integer,
 * n, as input and returns the nth ugly number. The method uses a set to store
 * the ugly numbers and iterates over the set to find the nth ugly number.
 *
 * Algorithm Complexity:
 * - The nthUglyNumber method has a time complexity of O(n), where n is the
 * input integer.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	int nthUglyNumber(int n) {
		set<long> mp;
		mp.insert(1);
		long num = 1;

		for (int i = 0; i < n; i++) {
			num = *mp.begin();
			mp.erase(num);
			mp.insert(num * 2);
			mp.insert(num * 3);
			mp.insert(num * 5);
		}

		return num;
	}
};
// @lc code=end
