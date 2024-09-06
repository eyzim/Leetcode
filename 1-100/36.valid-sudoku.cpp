/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * @brief Validate if a given 9x9 Sudoku board is valid. Only the filled cells
 * need to be validated according to the following rules:
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 * The solution provided here is a brute-force solution. It checks each row,
 * column and grid to see if there is any duplicate number. In the first
 * solution, it uses a hash set to store the numbers in each row, column and
 * grid. If there is any duplicate number, return false. For checking the grid,
 * it uses a vector of pairs to store the starting position of each grid. Then
 * it checks each grid by iterating through the 3x3 grid. In the second
 * solution, it uses three hash sets to store the numbers in each row, column
 * and grid. If there is any duplicate number, return false. The grid number is
 * calculated by (i/3)*3 + j/3.
 *
 * Algorithm Complexity:
 * - The time complexity is O(1) since the board is always 9x9.
 * - The space complexity is O(1) since the hash set is always 9.
 */

// @lc code=start
class Solution1 {
   public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> mp;

		// each row
		for (int i = 0; i < 9; i++) {
			mp.clear();
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && mp.count(board[i][j])) {
					return false;
				}
				mp.insert(board[i][j]);
			}
		}

		// each col
		for (int i = 0; i < 9; i++) {
			mp.clear();
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.' && mp.count(board[j][i])) {
					return false;
				}
				mp.insert(board[j][i]);
			}
		}

		// each grid
		vector<pair<int, int>> start;
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				start.push_back({i, j});
			}
		}

		for (auto s : start) {
			mp.clear();
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int px = s.first + i, py = s.second + j;
					cout << px << ", " << py << endl;
					if (board[px][py] != '.' && mp.count(board[px][py])) {
						return false;
					}
					mp.insert(board[px][py]);
				}
			}
		}

		return true;
	}
};
// @lc code=end

class Solution2 {
   public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> mpRow[9], mpCol[9], mpGrid[9];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char c = board[i][j];
				if (c == '.')
					continue;
				int grid = (i / 3) * 3 + j / 3;
				if (mpRow[i].count(c) || mpCol[j].count(c) ||
					mpGrid[grid].count(c)) {
					return false;
				}
				mpRow[i].insert(c);
				mpCol[j].insert(c);
				mpGrid[grid].insert(c);
			}
		}

		return true;
	}
};