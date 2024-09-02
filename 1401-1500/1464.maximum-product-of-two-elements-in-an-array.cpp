/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum product of two elements in an array.
 *
 * The Solution class provides a method, maxProduct, that takes a vector of
 * integers as input and returns an integer value representing the maximum
 * product of two elements in the array. The method sorts the array in ascending
 * order and returns the product of the two largest elements in the array.
 *
 * Algorithm Complexity:
 * - The maxProduct method has a time complexity of O(n*log(n)), where n is the
 * number of elements in the array.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   public:
	int maxProduct(vector<int>& nums) {
		ranges::sort(nums);
		int s = nums.size();

		return (nums[s - 1] - 1) * (nums[s - 2] - 1);
	}
};
// @lc code=end
