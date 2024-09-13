/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * string to an integer.
 *
 * The Solution class provides a method, myAtoi, that takes a string, s, as
 * input and converts it to an integer. The method initializes a long long int
 * variable, ans, to 0, an int variable, sign, to 1, and two bool variables,
 * startNum and startSign, to false. It then iterates through the string,
 * skipping leading whitespaces, checking for a sign, and processing digits. The
 * method checks for overflow before adding a digit and after the loop. Finally,
 * it returns the integer value of ans multiplied by the sign.
 *
 * Algorithm Complexity:
 * - The myAtoi method has a time complexity of O(n), where n is the length of
 * the input string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int myAtoi(string s) {
		long long int ans = 0;
		int sign = 1;
		bool startNum = false, startSign = false;

		for (auto i = 0; i < s.size(); i++) {
			if (!startNum && !startSign) {
				// Skip leading whitespaces
				if (s[i] == ' ')
					continue;
				// Check for sign, and the sign can only appear once
				if (s[i] == '+' || s[i] == '-') {
					sign = s[i] == '-' ? -1 : 1;
					startSign = true;
					continue;
				}
			}

			// Process digits
			if (isdigit(s[i])) {
				startNum = true;

				// Check for overflow before adding the digit
				if (ans > (INT_MAX / 10)) {
					return sign == 1 ? INT_MAX : INT_MIN;
				}
				ans = ans * 10 + (s[i] - '0');
			} else {
				break;
			}
		}

		// Check for overflow after the loop
		if (ans > INT_MAX) {
			return sign == 1 ? INT_MAX : INT_MIN;
		}

		return ans * sign;
	}
};
// @lc code=end
