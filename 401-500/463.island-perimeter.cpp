/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the perimeter of an island.
 *
 * The Solution class provides a method, islandPerimeter, that takes a 2D grid
 * of integers as input and returns an integer value representing the perimeter
 * of the island. The grid represents a map of land and water, where 0
 * represents water and 1 represents land. The island is a single connected land
 * mass, and the perimeter is the total length of the boundary between the land
 * and water. The method uses a depth-first search (DFS) approach to traverse
 * the island and calculate the perimeter. If the current cell is out of bounds
 * or is water, the method returns 1. If the current cell is land, the method
 * marks the cell as visited and recursively calls itself on the adjacent cells.
 * The method returns the sum of the perimeter of the adjacent cells.
 *
 * Algorithm Complexity:
 * - The islandPerimeter method has a time complexity of O(n^2), where n is the
 * size of the square grid.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   private:
	int dfs(vector<vector<int>>& grid, int i, int j) {
		// If the current cell is out of bounds or is water, return 1.
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
			grid[i][j] == 0)
			return 1;
		// If the current cell is visited, return 0.
		if (grid[i][j] == -1)
			return 0;

		// Mark the current cell as visited.
		grid[i][j] = -1;

		// Recursively call the method on the adjacent cells.
		return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) +
			   dfs(grid, i, j + 1);
	}

   public:
	int islandPerimeter(vector<vector<int>>& grid) {
		for (auto i = 0; i < grid.size(); i++) {
			for (auto j = 0; j < grid[0].size(); j++) {
				if (grid[i][j]) {
					return dfs(grid, i, j);
				}
			}
		}

		return 0;
	}
};
// @lc code=end
