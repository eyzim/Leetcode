/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if the input string is valid parentheses.
 *
 * The solution uses a stack to store the opening parentheses. It then iterates
 * through the input string and checks if the closing parentheses match the
 * opening parentheses. If they match, it pops the opening parentheses from the
 * stack. If they do not match, it returns false. If the stack is empty at the
 * end of the iteration, it returns true; otherwise, it returns false.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * input string.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	bool isValid(string s) {
		stack<char> st;

		for (auto i : s) {
			if (i == '(' || i == '[' || i == '{') {
				st.push(i);
			} else {
				// Check if the stack is empty
				if (st.empty())
					return false;
				// Check if the closing parentheses match the opening
				// parentheses
				if ((i == ')' && st.top() != '(') ||
					(i == ']' && st.top() != '[') ||
					(i == '}' && st.top() != '{')) {
					return false;
				}
				st.pop();
			}
		}

		return st.empty();
	}
};
// @lc code=end
