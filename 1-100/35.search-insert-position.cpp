/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * @brief The implementation of the Solution class, which is used to find the
 * index of the target element in a sorted array.
 *
 * The Solution class provides a method, searchInsert, that takes a vector of
 * integers, nums, and an integer, target, as input and returns the index of the
 * target element in the array. If the target element is not present in the
 * array, the method returns the index where the target element should be
 * inserted to maintain the sorted order.
 *
 * Algorithm Complexity:
 * - The searchInsert method has a time complexity of O(logn), where n is the
 * number of elements in the input array.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int searchInsert(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;

		while (start <= end) {
			// Find the middle element
			int mid = start + ((end - start) >> 1);

			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] > target) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return start;
	}
};
// @lc code=end
