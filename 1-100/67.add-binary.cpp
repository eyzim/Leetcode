/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * @brief The implementation of the Solution class, which is used to add two
 * binary strings.
 *
 * The Solution class provides a method, addBinary, that takes two binary
 * strings as input and returns the sum of the two binary strings. The binary
 * strings are represented as strings of '0's and '1's. The method adds the two
 * binary strings and returns the sum as a binary string.
 *
 * Algorithm Complexity:
 * - The addBinary method has a time complexity of O(n), where n is the length
 * of the longer of the two input strings.
 * - The space complexity of the addBinary method is O(n), where n is the length
 * of the longer of the two input strings.
 *
 */

// @lc code=start
class Solution {
   public:
	string addBinary(string a, string b) {
		string ans = "";
		// Initialize the carry and the pointers to the end of the strings.
		int cnt = 0, p1 = a.size() - 1, p2 = b.size() - 1;

		while (p1 >= 0 || p2 >= 0 || cnt) {
			// Add the digits from the end of the strings.
			if (p1 >= 0)
				cnt += a[p1--] - '0';
			if (p2 >= 0)
				cnt += b[p2--] - '0';
			// Append the sum of the digits to the answer.
			ans = char(cnt % 2 + '0') + ans;
			// Update the carry.
			cnt /= 2;
		}

		return ans;
	}
};
// @lc code=end
