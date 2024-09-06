/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * @brief The implementation of the Solution class, which is used to find the
 * indices of the two numbers that add up to a specific target.
 *
 * The solution uses a map to store the indices of the elements. It then
 * iterates through the array and calculates the difference between the target
 * and the current element. It checks if the difference is present in the map.
 * If it is present, it returns the indices of the two numbers. If it is not
 * present, it stores the current element in the map.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * array.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// Create a map to store the indices of the elements
		unordered_map<int, int> mp;

		for (auto i = 0; i < nums.size(); i++) {
			// Calculate the difference between the target and the current
			// element
			int t = target - nums[i];
			// Check if the difference is present in the map
			if (mp[t]) {
				return {mp[t] - 1, i};
			}
			mp[nums[i]] = i + 1;
		}

		return {};
	}
};
// @lc code=end
