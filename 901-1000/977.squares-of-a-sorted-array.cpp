/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * @brief The implementation of the Solution class, which is used to return the
 * squares of the elements in a sorted array.
 *
 * The Solution class provides a method, sortedSquares, that takes a vector of
 * integers as input and returns a vector of integers containing the squares of
 * the elements in the input array in non-decreasing order. The method uses a
 * two-pointer approach to iterate through the input array from both ends and
 * calculates the squares of the elements in non-decreasing order. The squares
 * are then stored in a new vector and returned as the output.
 *
 * Algorithm Complexity:
 * - The sortedSquares method has a time complexity of O(n), where n is the
 * number of elements in the input array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the input array.
 */

// @lc code=start
class Solution {
   public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> ans(nums.size());

		int left = 0, right = nums.size() - 1, index = nums.size() - 1;

		while (left <= right) {
			if (abs(nums[left]) >= nums[right]) {
				ans[index] = nums[left] * nums[left];
				left++;
			} else {
				ans[index] = nums[right] * nums[right];
				right--;
			}
			index--;
		}

		return ans;
	}
};
// @lc code=end
