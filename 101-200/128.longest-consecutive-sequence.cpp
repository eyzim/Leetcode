/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * @brief The implementation of the Solution class, which is used to find the
 * length of the longest consecutive sequence of numbers in an array.
 *
 * The Solution class provides a method, longestConsecutive, that takes a vector
 * of integers as input and returns an integer value representing the length of
 * the longest consecutive sequence of numbers in the array. The method first
 * removes duplicates from the input array and then sorts the array. It then
 * iterates through the array to find the longest consecutive sequence of
 * numbers. The method returns the length of the longest consecutive sequence.
 *
 * Algorithm Complexity:
 * - The longestConsecutive method has a time complexity of O(n*log(n)), where n
 * is the size of the input array.
 * - The space complexity of the method is O(n), where n is the size of the
 * input array.
 */

// @lc code=start
class Solution {
   public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();

		// Remove duplicates
		unordered_set<int> mp(nums.begin(), nums.end());
		nums.clear();
		for (auto i : mp) {
			nums.push_back(i);
		}
		// Sort the array
		ranges::sort(nums);

		// Find the longest consecutive sequence
		int cons = 1, maxi = 1;
		for (auto i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1] + 1) {
				cons++;
				maxi = max(cons, maxi);
			} else {
				cons = 1;
			}
		}

		return maxi;
	}
};
// @lc code=end
