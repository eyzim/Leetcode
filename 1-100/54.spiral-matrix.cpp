/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * @brief The implementation of the Solution class, which is used to return all
 * elements of the matrix in spiral order.
 *
 * The Solution class provides a method, spiralOrder, that takes a vector of
 * vectors of integers, matrix, as input and returns all elements of the matrix
 * in spiral order. It initializes four integers, left, up, right, and down, to
 * the boundaries of the matrix. It then iterates over the matrix in a spiral
 * order, adding the elements to the answer vector. The method returns the
 * answer vector.
 *
 * Algorithm Complexity:
 * - The spiralOrder method has a time complexity of O(m*n), where m is the
 * number of columns and n is the number of rows in the matrix.
 * - The space complexity of the method is O(m*n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return {};

		int m = matrix[0].size(), n = matrix.size();
		vector<int> ans;

		// Initialize the four boundaries of the matrix
		int left = 0, up = 0, right = m - 1, down = n - 1;
		while (left <= right && up <= down) {
			// go right
			for (int i = left; i <= right; i++) {
				ans.push_back(matrix[up][i]);
			}
			up++;

			// go down
			for (int i = up; i <= down; i++) {
				ans.push_back(matrix[i][right]);
			}
			right--;

			// go left
			for (int i = right; i >= left && up <= down; i--) {
				ans.push_back(matrix[down][i]);
			}
			down--;

			// go up
			for (int i = down; i >= up && left <= right; i--) {
				ans.push_back(matrix[i][left]);
			}
			left++;
		}

		return ans;
	}
};
// @lc code=end
