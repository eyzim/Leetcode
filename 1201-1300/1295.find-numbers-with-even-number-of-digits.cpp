/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 *
 * @brief The implementation of the Solution class, which is used to find the
 * number of integers with an even number of digits.
 *
 * The Solution class provides a method, findNumbers, that takes a vector of
 * integers as input and returns the number of integers with an even number of
 * digits.
 *
 * Algorithm Complexity:
 * - The findNumbers method has a time complexity of O(n), where n is the number
 * of elements in the input vector.
 * - The space complexity of the findNumbers method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int findNumbers(vector<int>& nums) {
		int ans = 0;

		for (auto i : nums) {
			int digit = 0;
			while (i) {
				i /= 10;
				digit++;
			}
			if (digit % 2 == 0) {
				ans++;
			}
		}

		return ans;
	}
};
// @lc code=end
