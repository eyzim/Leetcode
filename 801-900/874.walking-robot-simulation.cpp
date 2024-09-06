/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the maximum Euclidean distance that the robot can walk.
 *
 * The solution uses a set to store the obstacles as strings, which is more
 * efficient than a two-dimensional vector. It then initializes the face
 * direction and the current position of the robot. It calculates the maximum
 * Euclidean distance that the robot can walk by iterating through the commands.
 * If the command is to change directions, it updates the face direction
 * accordingly. If the command is to move forward, it moves the robot one step
 * at a time and checks if there is an obstacle in the way. If there is an
 * obstacle, it stops moving. Finally, it returns the maximum Euclidean distance
 * that the robot can walk.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * commands.
 * - The solution has a space complexity of O(m), where m is the size of the
 * obstacles.
 */

// @lc code=start
class Solution {
   public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		// store the obstacles as a set of strings, which is more efficient than
		// a two-dimensional vector
		unordered_set<string> mp;
		for (auto i : obstacles) {
			int x = i[0], y = i[1];
			mp.insert(to_string(i[0]) + ',' + to_string(i[1]));
		}

		// face dir: up, right, down and left
		int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int face = 0;

		// current position
		int x = 0, y = 0;

		// get the max euclidean distance
		int ans = 0;

		for (auto i : commands) {
			// change directions
			if (i == -1 || i == -2) {
				if (i == -1)
					face = (face + 1) % 4;
				else if (i == -2)
					face = (face + 3) % 4;
				continue;
			}

			// move forward i steps, one step by one step, check if there is an
			// obstacle, if there is, stop moving
			while (i) {
				string nextStr = to_string(x + dir[face][0]) + ',' +
								 to_string(y + dir[face][1]);
				if (mp.count(nextStr)) {
					break;
				}
				x += dir[face][0];
				y += dir[face][1];
				i--;
			}

			// get the max euclidean distance
			int len = pow(x, 2) + pow(y, 2);
			ans = max(len, ans);
		}

		return ans;
	}
};
// @lc code=end
