/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * 1D array into a 2D array.
 *
 * The Solution class provides a method, construct2DArray, that takes a vector
 * of integers, original, and two integers, m and n, as input and returns a 2D
 * array. The method constructs the 2D array by filling it row by row with the
 * elements from the original array. If the original array does not have enough
 * elements to fill the 2D array, the method returns an empty array.
 *
 * Algorithm Complexity:
 * - The construct2DArray method has a time complexity of O(m*n), where m is the
 * number of rows and n is the number of columns in the 2D array.
 * - The space complexity of the method is O(m*n).
 */

// @lc code=start
class Solution {
   public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		// Check if the original array has enough elements to fill the 2D array,
		// return an empty array if not enough elements
		if (original.size() != m * n)
			return {};

		vector<vector<int>> ans(m, vector<int>(n, 0));
		int pos = 0;

		// Fill the 2D array row by row
		for (auto i = 0; i < m; i++) {
			for (auto j = 0; j < n; j++) {
				ans[i][j] = original[pos];
				pos++;
			}
		}

		return ans;
	}
};
// @lc code=end
