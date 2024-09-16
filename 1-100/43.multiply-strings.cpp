/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * @brief : Given two non-negative integers num1 and num2 represented as
 * strings, return the product of num1 and num2, also represented as a string.
 *
 * The length of both num1 and num2 is < 110, we can't use int or long long to
 * store the result. The solution is to use a vector to store the result. The
 * size of the vector is the sum of the length of num1 and num2. The product of
 * two digits at position i and j will be stored at position i+j and i+j+1. The
 * final result is the sum of the vector. When we convert the vector to a
 * string, we need to skip the leading zeros.
 *
 * Algorithm Complexity:
 * - Time: O(n*m), where n is the length of num1 and m is the length of num2.
 * - Space: O(n+m), to store the result.
 */

// @lc code=start
class Solution {
   public:
	string multiply(string num1, string num2) {
		// If any of the number is 0, return 0
		if (num1 == "0" || num2 == "0")
			return "0";

		int p1 = num1.size() - 1, p2 = num2.size() - 1;
		vector<int> num(p1 + p2 + 2, 0);

		for (int i = p2; i >= 0; i--) {
			for (int j = p1; j >= 0; j--) {
				// num[i + j + 1] is the current digit, num[i + j] is the carry
				// over
				num[i + j + 1] += (num1[j] - '0') * (num2[i] - '0');
				num[i + j] += num[i + j + 1] / 10;
				num[i + j + 1] %= 10;
			}
		}

		string ans = "";
		for (auto i = 0; i < num.size(); i++) {
			// Skip leading zeros
			if (ans.size() == 0 && num[i] == 0) {
				continue;
			}
			ans += (num[i] + '0');
		}

		return ans;
	}
};
// @lc code=end
