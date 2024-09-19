/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * @brief : Given a string of numbers and operators, return all possible results
 * from computing all the different possible ways to group numbers and
 * operators. The valid operators are +, - and *.
 *
 * The idea is to divide the expression into two parts and recursively calculate
 * the result for each part. Then combine the results for the two parts. The
 * base case is when the expression contains only a number, in which case the
 * result is the number itself.
 *
 *
 * Example: exp = "2*3-4*5"
 *
 * First Call: diffWaysToCompute("2*3-4*5")
 *
 * Operators: *, -, *
 * Splits into:
 * left = diffWaysToCompute("2")
 * right = diffWaysToCompute("3-4*5")
 * Second Call: diffWaysToCompute("3-4*5")
 *
 * Operators: -, *
 * Splits into:
 * left = diffWaysToCompute("3")
 * right = diffWaysToCompute("4*5")
 * Third Call: diffWaysToCompute("4*5")
 *
 * Operator: *
 * Splits into:
 * left = diffWaysToCompute("4")
 * right = diffWaysToCompute("5")
 * Base Cases:
 *
 * diffWaysToCompute("2") returns [2]
 * diffWaysToCompute("3") returns [3]
 * diffWaysToCompute("4") returns [4]
 * diffWaysToCompute("5") returns [5]
 * Combining Results:
 *
 * diffWaysToCompute("4*5"):
 * left = [4], right = [5]
 * perform(4, 5, '*') returns 20
 * ans = [20]
 * diffWaysToCompute("3-4*5"):
 * left = [3], right = [20]
 * perform(3, 20, '-') returns -17
 * ans = [-17]
 * diffWaysToCompute("2*3-4*5"):
 * left = [2], right = [-17]
 * perform(2, -17, '*') returns -34
 * ans = [-34]
 *
 * Algorithm Complexity:
 * - Time: O(2^n)
 * - Space: O(2^n)
 */

// @lc code=start
class Solution {
   private:
	int perform(int x, int y, char operation) {
		if (operation == '+')
			return x + y;
		if (operation == '-')
			return x - y;
		if (operation == '*')
			return x * y;
		return 0;
	}

   public:
	vector<int> diffWaysToCompute(string exp) {
		vector<int> ans;

		for (auto i = 0; i < exp.size(); i++) {
			if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
				// divide the expression into two parts
				vector<int> left = diffWaysToCompute(exp.substr(0, i));
				vector<int> right = diffWaysToCompute(exp.substr(i + 1));

				// combine the results for the two parts
				for (auto x : left) {
					for (auto y : right) {
						int val = perform(x, y, exp[i]);
						ans.push_back(val);
					}
				}
			}
		}

		// if there is no more operators, the expression is a single number now.
		if (ans.empty()) {
			ans.push_back(stoi(exp));
		}
		return ans;
	}
};
// @lc code=end
