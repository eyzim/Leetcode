/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum number of different types of candies the girl can get.
 *
 * The solution uses a set to store the different types of candies. It then
 * calculates the minimum of the number of different types of candies and half
 * of the total number of candies to find the maximum number of different types
 * of candies the girl can get.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * candyType vector.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	int distributeCandies(vector<int>& candyType) {
		// Create a set to store the different types of candies
		set<int> mp(candyType.begin(), candyType.end());

		// Calculate the minimum of the number of different types of candies and
		// half of the total number of candies
		return min(mp.size(), candyType.size() / 2);
	}
};
// @lc code=end
