/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 *
 * @brief The implementation of the Solution class, which is used to concatenate
 * an array with itself.
 *
 * The Solution class provides a method, getConcatenation, that takes a vector
 * of integers, nums, as input and returns a vector of integers that is the
 * concatenation of nums with itself.
 *
 * Algorithm Complexity:
 * - Time complexity is O(n), where n is the number of elements in the input
 * vector.
 * - Space complexity is O(1).
 */

// @lc code=start
class Solution {
   public:
	vector<int> getConcatenation(vector<int>& nums) {
		nums.insert(nums.end(), nums.begin(), nums.end());

		return nums;
	}
};
// @lc code=end
