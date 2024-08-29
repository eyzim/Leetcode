/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * @brief The implementation of the Solution class, which is used to rotate the
 * image.
 *
 * The Solution class provides a method, rotate, that takes a 2D vector of
 * integers as input and rotates the image by 90 degrees clockwise. The method
 * first transposes the matrix through the main diagonal and then reverses the
 * matrix horizontally. The method does not return anything.
 *
 * Algorithm Complexity:
 * - The rotate method has a time complexity of O(n^2), where n is the size of
 * the square matrix.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 1)
			return;

		int mat = matrix.size() - 1;

		// Transpose the matrix through the main diagonal.
		for (auto i = 0; i <= mat; i++) {
			for (auto j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		// Reverse the matrix horizontally.
		for (auto i = 0; i <= mat; i++) {
			for (auto j = 0; j <= mat >> 1; j++) {
				swap(matrix[i][j], matrix[i][mat - j]);
			}
		}
	}
};
// @lc code=end
