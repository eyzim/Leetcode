/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 *
 * @brief The implementation of the Solution class, which is used to find the
 * kids with the greatest number of candies.
 *
 * The Solution class provides a method, check the kids with the greatest number
 * of candies and then set the target candies to the kids who cannot have the
 * greatest number of candies even after adding the extra candies.
 *
 * Algorithm Complexity:
 * - The kidsWithCandies method has a time complexity of O(n), where n is the
 * length of the input vector.
 * - The space complexity of the kidsWithCandies method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int target = 0;

		for (const auto i : candies) {
			target = max(target, i);
		}

		target -= extraCandies;

		// Initialize the vector with the size of candies and set all the
		// elements to true
		vector<bool> ans(candies.size(), true);

		for (auto i = 0; i < candies.size(); i++) {
			if (candies[i] < target)
				ans[i] = false;
		}

		return ans;
	}
};
// @lc code=end
