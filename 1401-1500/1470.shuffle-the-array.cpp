/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 *
 * @brief The implementation of the Solution class, which is used to shuffle the
 * array.
 * Given the array nums consisting of 2n elements in the form [x1, x2, ..., xn,
 * y1, y2, ..., yn]. Organize the array such that the resulting array is [x1,
 * y1, x2, y2, ..., xn, yn].
 *
 * The Solution class provides a method, shuffle, that takes a vector of
 * integers and an integer n as input and returns the shuffled array. The method
 * iterates through the input array and constructs the shuffled array by
 * interleaving the elements of the input array. The shuffled array is then
 * returned as the output.
 *
 * Algorithm Complexity:
 * - The shuffle method has a time complexity of O(n), where n is the number of
 * input elements.
 * - The space complexity of the method is O(n), where n is the number of input
 * elements.
 */

// @lc code=start
class Solution {
   public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> ans;

		for (auto i = 0; i < n; i++) {
			ans.push_back(nums[i]);
			ans.push_back(nums[i + n]);
		}

		return ans;
	}
};
// @lc code=end
