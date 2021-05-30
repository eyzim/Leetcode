/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the sum of the previous elements in an array.
 *
 * The Solution class provides a method, runningSum, that takes an array of
 * integers as input and returns an array where the ith element is the sum of
 * the first i + 1 elements from the original array.
 *
 * Algorithm Complexity:
 * - The runningSum method has a time complexity of O(n), where n is the length
 * of the input array.
 * - The space complexity of the runningSum method is O(1).
 */

// @lc code=start
class Solution {
   public:
	vector<int> runningSum(vector<int>& nums) {
		if (nums.size() == 1)
			return nums;

		for (auto i = 1; i < nums.size(); i++) {
			nums[i] += nums[i - 1];
		}

		return nums;
	}
};
// @lc code=end
