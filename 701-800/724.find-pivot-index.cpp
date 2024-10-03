/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * @brief The implementation of the Solution class, which is used to find the
 * pivot index of a given array.
 *
 * The pivot index is defined as the index where the sum of all elements to the
 * left of the index is equal to the sum of all elements to the right of the
 * index. The Solution class provides a method, pivotIndex, that takes a vector
 * of integers nums as input and returns the pivot index of the array. The
 * method uses a linear approach to calculate the sum of all elements and the
 * sum of the left cut by the pivot. The final result is then returned based on
 * the sum of the left and right cuts.
 *
 * Algorithm Complexity:
 * - The pivotIndex method has a time complexity of O(n), where n is the number
 * of elements in the array.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;

		// sum of all elements
		int total = accumulate(nums.begin(), nums.end(), 0);
		// sum of left cut by pivot
		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			// if sum of left == sum of right
			if (sum == total - sum - nums[i]) {
				return i;
			}
			sum += nums[i];
		}

		return -1;
	}
};
// @lc code=end
