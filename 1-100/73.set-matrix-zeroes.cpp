/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * @brief The implementation of the Solution class, which is used to set the
 * rows and columns of a matrix to zero if the element at that position is zero.
 *
 * The Solution class provides a method, setZeroes, that takes a vector of
 * vectors of integers matrix as input and sets the rows and columns of the
 * matrix to zero if the element at that position is zero. The method uses a set
 * to store the row and column indices where the element is zero. It then
 * iterates over the matrix and sets the rows and columns to zero based on the
 * indices stored in the set.
 *
 * Algorithm Complexity:
 * - The setZeroes method has a time complexity of O(m*n), where m is the number
 * of rows and n is the number of columns in the matrix.
 * - The space complexity of the method is O(m+n), where m is the number of rows
 * and n is the number of columns in the matrix.
 */

// @lc code=start
class Solution {
   public:
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> row, col;

		// Store the row and column indices where the element is zero.
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					row.insert(i);
					col.insert(j);
				}
			}
		}

		// Set the rows based on the indices stored in the set.
		for (auto r : row) {
			for (int i = 0; i < matrix[0].size(); i++) {
				matrix[r][i] = 0;
			}
		}

		// Set the columns based on the indices stored in the set.
		for (auto c : col) {
			for (int i = 0; i < matrix.size(); i++) {
				matrix[i][c] = 0;
			}
		}
	}
};
// @lc code=end
