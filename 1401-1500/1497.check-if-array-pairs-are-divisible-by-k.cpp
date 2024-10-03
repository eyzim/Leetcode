/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 *
 * @brief The implementation of the Solution class, which is used to check if
 * the array pairs are divisible by k.
 *
 * Given an array of integers arr of even length n and an integer k. We want to
 * divide the array into exactly n / 2 pairs such that the sum of each pair is
 * divisible by k. Return True If you can find a way to do that or False
 * otherwise. First, we have to check if the array pairs are divisible by k. The
 * Solution class provides a method, canArrange, that takes a vector of integers
 * arr and an integer k as input and returns a boolean value based on whether
 * the array pairs are divisible by k. The method uses a hash map to store the
 * remainder of each element in the array when divided by k. It then checks if
 * the number of elements with remainder 0 is even and if the number of elements
 * with remainder i is equal to the number of elements with remainder k - i. The
 * final result is then returned based on these conditions.
 *
 * Algorithm Complexity:
 * - The canArrange method has a time complexity of O(n), where n is the number
 * of elements in the array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the array.
 */

// @lc code=start
class Solution {
   public:
	bool canArrange(vector<int>& arr, int k) {
		unordered_map<int, int> mp;

		// Store the remainder of each element in the array when divided by k
		for (auto i : arr) {
			i %= k;
			// If the remainder is negative, add k to it to make it positive
			if (i < 0) {
				i += k;
			}
			mp[i]++;
		}

		// If the number of elements with remainder 0 is odd, means there is one
		// element which is not paired with any other element
		if (mp[0] % 2) {
			return false;
		}

		// Check if the number of elements with remainder i is equal to the
		// number of elements with remainder k - i
		for (int i = 1; i <= (k >> 1); i++) {
			if (mp[i] != mp[k - i]) {
				return false;
			}
		}

		return true;
	}
};
// @lc code=end
