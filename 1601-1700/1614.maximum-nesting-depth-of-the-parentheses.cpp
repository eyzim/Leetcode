/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum nesting depth of the parentheses.
 * Mind that there is no need to check the maximun number.
 *
 * The Solution class provides a method, maxDepth, that takes a string, s, as
 * input and returns the maximum nesting depth of the parentheses. The method
 * initializes a stack of characters, st, and a variable, maxi, to 0. It then
 * iterates through the string, s, and pushes an opening parenthesis onto the
 * stack and updates the maximum nesting depth if the size of the stack is
 * greater than maxi. If a closing parenthesis is encountered, the method pops
 * the top element from the stack. Finally, the method returns maxi.
 *
 * Algorithm Complexity:
 * - The maxDepth method has a time complexity of O(n), where n is the length of
 * the string, s.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int maxDepth(string s) {
		stack<char> st;
		int maxi = 0;

		for (auto i : s) {
			if (i == '(') {
				int size = st.size();
				st.push('(');
				maxi = max(maxi, size);
			} else if (i == ')') {
				st.pop();
			}
		}

		return maxi;
	}
};
// @lc code=end
