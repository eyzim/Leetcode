/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * @brief The implementation of the Solution class, which is used to generate a
 * spiral matrix.
 *
 * The Solution class provides a method, generateMatrix, that takes an integer,
 * n, as input and returns a spiral matrix of size n x n. The method initializes
 * a vector of vectors, ans, of size n x n, and four integers, left, up, right,
 * and down, to 0, 0, n - 1, and n - 1, respectively. It then fills the matrix
 * with the values from 1 to n * n in a spiral order. The method returns the
 * spiral matrix.
 *
 * Algorithm Complexity:
 * - The generateMatrix method has a time complexity of O(n^2), where n is the
 * size of the spiral matrix.
 * - The space complexity of the method is O(n^2).
 */

// @lc code=start
class Solution {
   public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n));

		int left = 0, up = 0, right = n - 1, down = n - 1;
		int num = 1;
		while (left <= right && up <= down) {
			// go right
			for (int i = left; i <= right; i++) {
				ans[up][i] = num;
				num++;
			}
			up++;

			// go down
			for (int i = up; i <= down; i++) {
				ans[i][right] = num;
				num++;
			}
			right--;

			// go left
			for (int i = right; i >= left && up <= down; i--) {
				ans[down][i] = num;
				num++;
			}
			down--;

			// go up
			for (int i = down; i >= up && left <= right; i--) {
				ans[i][left] = num;
				num++;
			}
			left++;
		}

		return ans;
	}
};
// @lc code=end
