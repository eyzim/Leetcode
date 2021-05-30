/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * @brief The implementation of the Solution class, which is used to sort an
 * array of integers by parity.
 *
 * The Solution class provides a method, sortArrayByParity, that swaps the
 * elements of the input array such that all even elements appear before the odd
 * elements.
 *
 * Algorithm Complexity:
 * - The sortArrayByParity method has a time complexity of O(n), where n is the
 * length of the input array.
 * - The space complexity of the sortArrayByParity method is O(1).
 */

// @lc code=start
class Solution {
   public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;

		while (start < end) {
			if (nums[start] % 2 == 0) {
				start++;
				continue;
			}
			if (nums[end] % 2 == 1) {
				end--;
				continue;
			}

			if ((nums[start] % 2 == 1) && (nums[end] % 2 == 0)) {
				swap(nums[start], nums[end]);
				start++;
				end--;
			}
		}

		return nums;
	}
};
// @lc code=end
