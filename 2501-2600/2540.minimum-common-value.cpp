/*
 * @lc app=leetcode id=2540 lang=cpp
 *
 * [2540] Minimum Common Value
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum common value between two arrays.
 *
 * The Solution class provides a method, getCommon, that takes two vectors of
 * integers as input and returns the minimum common value between the two
 * arrays. The method uses two pointers to iterate over the two arrays and find
 * the common value.
 *
 * Algorithm Complexity:
 * - The getCommon method has a time complexity of O(n + m), where n and m are
 * the lengths of the two input arrays.
 * - The space complexity of the getCommon method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		int p = 0, q = 0;

		while (p < nums1.size() && q < nums2.size()) {
			if (nums1[p] == nums2[q]) {
				return nums1[p];
			} else if (nums1[p] < nums2[q]) {
				p++;
			} else {
				q++;
			}
		}

		return -1;
	}
};
// @lc code=end
