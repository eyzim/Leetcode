/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 *
 * @brief The implementation of the Solution class, which is used to add and
 * subtract fractions.
 *
 * The Solution class provides a method, fractionAddition, that takes a string
 * as input and returns the sum of the fractions in the string. First, the
 * string is split into an integer array. Then, the common multiple of the
 * denominators is calculated. Next, the fractions are added and abstracted.
 * Finally, the greatest common divisor (gcd) is calculated, and the sum is
 * converted into a string.
 *
 * Algorithm Complexity:
 * - The time complexity of O(n), where n is the length of the input string.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	string fractionAddition(string expression) {
		// split the string into int array
		vector<int> split;
		string t = "";
		for (int i = expression.size() - 1; i >= 0; i--) {
			if (!isdigit(expression[i])) {
				if (expression[i] != '/') {
					t = expression[i] + t;
				}
				split.insert(split.begin(), stoi(t));
				t = "";
			} else {
				t = expression[i] + t;
			}
		}
		if (t.size()) {
			split.insert(split.begin(), stoi(t));
		}

		// find common multiple
		unordered_set<int> mp;
		for (int i = 1; i < split.size(); i += 2) {
			mp.insert(split[i]);
		}
		int commonMulti = 1;
		for (auto i : mp) {
			commonMulti *= i;
		}

		// addition and abstraction
		int sum = 0;
		for (int i = 0; i < split.size(); i += 2) {
			int m = commonMulti / split[i + 1];
			split[i] *= m;
			split[i + 1] = commonMulti;
			sum += split[i];
		}

		// find gcd
		int gcd = __gcd(abs(sum), commonMulti);
		sum /= gcd;
		commonMulti /= gcd;

		// convert into string
		if (sum == 0) {
			return "0/1";
		}

		return to_string(sum) + '/' + to_string(commonMulti);
		;
	}
};
// @lc code=end
