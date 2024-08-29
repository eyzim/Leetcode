/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of islands in a 2D grid.
 *
 * The Solution class provides a method, numIslands, that takes a 2D vector of
 * characters as input and returns an integer value representing the number of
 * islands in the grid. The grid represents a map of land and water, where '0'
 * represents water and '1' represents land. An island is a group of connected
 * land cells, where a cell is considered connected to another cell if they are
 * adjacent horizontally or vertically. The method uses a depth-first search
 * (DFS) approach to traverse the grid and count the number of islands. If the
 * current cell is out of bounds or is water, the method returns. If the current
 * cell is land, the method marks the cell as visited and recursively calls
 * itself on the adjacent cells. The method returns the count of the number of
 * islands in the grid.
 *
 * Algorithm Complexity:
 * - The numIslands method has a time complexity of O(n*m), where n is the
 * number of rows and m is the number of columns in the grid.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   private:
	void dfs(vector<vector<char>>& grid, int i, int j) {
		// If the current cell is out of bounds or is water, return.
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
			grid[i][j] == '0')
			return;

		// Mark the current cell as visited.
		grid[i][j] = '0';

		// Recursively call the method on the adjacent cells.
		dfs(grid, i - 1, j);
		dfs(grid, i + 1, j);
		dfs(grid, i, j - 1);
		dfs(grid, i, j + 1);
	}

   public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;

		for (auto i = 0; i < grid.size(); i++) {
			for (auto j = 0; j < grid[i].size(); j++) {
				// If the current cell is land, increment the count and call the
				// dfs method.
				if (grid[i][j] == '1') {
					count++;
					dfs(grid, i, j);
				}
			}
		}

		return count;
	}
};
// @lc code=end
