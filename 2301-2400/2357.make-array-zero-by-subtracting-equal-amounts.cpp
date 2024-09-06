/*
 * @lc app=leetcode id=2357 lang=cpp
 *
 * [2357] Make Array Zero by Subtracting Equal Amounts
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum number of operations required to make all elements of the list zero.
 *
 * The solution uses a set to store the unique elements in the list. It then
 * extracts the zero from the set initially and returns the size of the set
 * minus the count of zero.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * list.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	int minimumOperations(vector<int>& nums) {
		// Create a set to store the unique elements in the list
		unordered_set<int> mp(nums.begin(), nums.end());

		// Extract the zero from the set initially
		return mp.size() - mp.count(0);
	}
};
// @lc code=end
