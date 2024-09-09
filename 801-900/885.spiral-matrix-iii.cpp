/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 *
 * @brief The implementation of the Solution class, which is used to return a
 * list of coordinates representing the positions of the cells in the matrix in
 * the order they are visited.
 *
 * The Solution class provides a method, spiralMatrixIII, that takes four
 * integers, rows, cols, rStart, and cStart, as input and returns a list of
 * coordinates representing the positions of the cells in the matrix in the
 * order they are visited. The method initializes a vector of vectors, ans, with
 * the starting coordinates and a variable, num, with a value of 1. It then
 * iterates through the matrix in a spiral pattern, adding the coordinates to
 * the ans vector as they are visited. Finally, it returns the ans vector.
 *
 * Algorithm Complexity:
 * - The spiralMatrixIII method has a time complexity of O(rows * cols), where
 * rows and cols are the number of rows and columns in the matrix, respectively.
 * - The space complexity of the method is O(rows * cols).
 */

// @lc code=start
class Solution {
   public:
	vector<vector<int>> spiralMatrixIII(int rows,
										int cols,
										int rStart,
										int cStart) {
		vector<vector<int>> ans = {{rStart, cStart}};
		int num = 1, len = 1;
		int x = rStart, y = cStart;

		// Iterate through the matrix in a spiral pattern
		while (num < rows * cols) {
			// go right
			for (int i = 0; i < len; i++) {
				y++;
				if (x >= 0 && x < rows && y >= 0 && y < cols) {
					ans.push_back({x, y});
					num++;
				}
			}

			// go down
			for (int i = 0; i < len; i++) {
				x++;
				if (x >= 0 && x < rows && y >= 0 && y < cols) {
					ans.push_back({x, y});
					num++;
				}
			}

			len++;

			// go left
			for (int i = 0; i < len; i++) {
				y--;
				if (x >= 0 && x < rows && y >= 0 && y < cols) {
					ans.push_back({x, y});
					num++;
				}
			}

			// go up
			for (int i = 0; i < len; i++) {
				x--;
				if (x >= 0 && x < rows && y >= 0 && y < cols) {
					ans.push_back({x, y});
					num++;
				}
			}

			len++;
		}

		return ans;
	}
};
// @lc code=end
