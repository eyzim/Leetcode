/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the total points of a baseball game.
 *
 * The Solution class provides a method, calPoints, that takes a vector of
 * strings, operations, as input and calculates the total points of a baseball
 * game. It uses a stack to keep track of the points and performs the operations
 * based on the input strings. The method returns the total points at the end.
 *
 * Algorithm Complexity:
 * - The calPoints method has a time complexity of O(n), where n is the number
 * of operations in the input vector.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	int calPoints(vector<string>& operations) {
		stack<int> st;
		for (const auto& i : operations) {
			if (i == "C") {
				st.pop();
			} else if (i == "D") {
				st.push(st.top() * 2);
			} else if (i == "+") {
				int top = st.top();
				st.pop();
				int newTop = top + st.top();
				st.push(top);
				st.push(newTop);
			} else {
				st.push(stoi(i));
			}
		}

		int ans = 0;
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		return ans;
	}
};
// @lc code=end
