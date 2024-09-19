/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * @brief The implementation of the Solution class, which is used to solve the
 * problem of surrounded regions.
 *
 * The Solution class provides a method, solve, that takes a 2D vector of
 * characters, board, as input and solves the problem of surrounded regions. It
 * first checks if the board is empty and then traverses the boundary of the
 * board. It marks all 'O's on the boundary as '#' and then traverses the board
 * to mark the remaining 'O's as 'X'. Finally, it traverses the board again to
 * mark the '#' as 'O', which are the regions that connect to the boundary.
 *
 * Algorithm Complexity:
 * - The solve method has a time complexity of O(m*n), where m is the number of
 * rows and n is the number of columns in the board.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   private:
	void dfs(vector<vector<char>>& board, int i, int j, char c) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
			board[i][j] == 'X' || board[i][j] == '#') {
			return;
		}

		board[i][j] = c;
		dfs(board, i + 1, j, c);
		dfs(board, i - 1, j, c);
		dfs(board, i, j + 1, c);
		dfs(board, i, j - 1, c);
	}

   public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) {
			return;
		}

		// Traverse the boundary and mark all 'O's as '#'
		for (auto i = 0; i < board[0].size(); i++) {
			dfs(board, 0, i, '#');
			dfs(board, board.size() - 1, i, '#');
		}
		for (auto i = 0; i < board.size(); i++) {
			dfs(board, i, 0, '#');
			dfs(board, i, board[0].size() - 1, '#');
		}

		// Traverse the board for remaining 'O's and mark them as 'X'
		for (auto i = 0; i < board.size(); i++) {
			for (auto j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O') {
					dfs(board, i, j, 'X');
				}
			}
		}

		// Traverse the board and mark '#' as 'O', which are the regions that
		// connect to the boundary
		for (auto i = 0; i < board.size(); i++) {
			for (auto j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '#') {
					board[i][j] = 'O';
				}
			}
		}
	}
};
// @lc code=end
