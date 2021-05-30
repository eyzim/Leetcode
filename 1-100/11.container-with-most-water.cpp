/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * @brief The implementation of the Solution class, which is used to find the
 * container with the most water.
 *
 * The Solution class provides a method, maxArea, that takes a vector of
 * integers as input and returns the maximum area of water that can be contained
 * by the given input.
 *
 * Algorithm Complexity:
 * - The maxArea method has a time complexity of O(n), where n is the length of
 * the input vector.
 * - The space complexity of the maxArea method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size() - 1;
		int ans = 0;

		// find the maximum area
		while (l < r) {
			ans = max(ans, (r - l) * min(height[l], height[r]));

			// move the pointer with the smaller height
			if (height[l] == height[r]) {
				l++;
				r--;
			} else if (height[l] < height[r]) {
				l++;
			} else {
				r--;
			}
		}

		return ans;
	}
};
// @lc code=end
