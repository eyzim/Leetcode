/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 *
 * @brief The implementation of the Solution class, which is used to remove the
 * outermost parentheses of a string.
 *
 * Solution1:
 * The Solution1 class provides a method, removeOuterParentheses, that takes a
 * string, s, as input and removes the outermost parentheses of the string. It
 * initializes an empty string, ans, and an integer, open, to 0. It then
 * iterates through the string and increments the open variable when it
 * encounters an opening parenthesis and decrements it when it encounters a
 * closing parenthesis. If the open variable is greater than 0, it appends the
 * current character to the ans string. Finally, it returns the ans string.
 *
 * Solution2:
 * The Solution2 class provides a method, removeOuterParentheses, that takes a
 * string, s, as input and removes the outermost parentheses of the string. It
 * initializes a stack of characters, st, and an empty string, ans. It then
 * iterates through the string and pushes an opening parenthesis onto the stack
 * and appends it to the ans string if the stack size is greater than 0. If it
 * encounters a closing parenthesis, it pops the stack and appends it to the ans
 * string if the stack size is greater than 1. Finally, it returns the ans
 * string.
 *
 * Algorithm Complexity:
 * - The removeOuterParentheses method has a time complexity of O(n), where n is
 * the length of the input string.
 * - The space complexity of the method is O(1) for solution1.
 * - The space complexity of the method is O(n) for solution2.
 */

// @lc code=start
class Solution1 {
   public:
	string removeOuterParentheses(string s) {
		string ans = "";
		int open = 0;

		for (auto i : s) {
			if (i == '(') {
				if (open > 0)
					ans += i;
				open++;
			} else {
				if (open > 1)
					ans += i;
				open--;
			}
		}

		return ans;
	}
};

class Solution2 {
   public:
	string removeOuterParentheses(string s) {
		stack<char> st;
		string ans = "";

		for (auto i : s) {
			if (i == '(') {
				if (st.size() > 0)
					ans += i;
				st.push('(');
			} else {
				if (st.size() > 1)
					ans += i;
				st.pop();
			}
		}

		return ans;
	}
};
// @lc code=end
