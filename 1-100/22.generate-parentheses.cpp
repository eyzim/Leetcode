/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * @brief: The implementation of the Solution class, which is used to generate
 * all valid combinations of n pairs of parentheses.
 *
 * The Solution class provides a method, generateParenthesis, that takes an
 * integer, n, as input and returns a vector of strings containing all valid
 * combinations of n pairs of parentheses. The method uses a recursive approach
 * to generate the combinations by adding opening and closing parentheses. It
 * starts with n opening and closing parentheses and recursively builds the
 * combinations by adding opening and closing parentheses until all the
 * parentheses are used.
 *
 * Algorithm Complexity:
 * - The generateParenthesis method has a time complexity of O(4^n/sqrt(n)),
 * where n is the number of pairs of parentheses.
 * - The space complexity of the method is O(4^n/sqrt(n)).
 */

// @lc code=start
class Solution {
   private:
	void build(string per, int open, int close, vector<string>& ans) {
		// If more closing parentheses are used than opening, it's invalid
		if (open > close)
			return;
		// If no more opening parentheses left, append the remaining closing
		// ones
		if (open == 0) {
			per.append(close, ')');
			ans.push_back(per);
			return;
		}

		// Recursively by adding opening and closing parentheses
		build(per + "(", open - 1, close, ans);
		build(per + ")", open, close - 1, ans);
	}

   public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;

		build("", n, n, ans);

		return ans;
	}
};
// @lc code=end
