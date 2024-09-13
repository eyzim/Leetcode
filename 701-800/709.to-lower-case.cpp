/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * string to lowercase.
 *
 * The Solution class provides a method, toLowerCase, that takes a string, s, as
 * input and converts it to lowercase. It iterates through the string and checks
 * if the character is an uppercase letter. If it is, it converts it to
 * lowercase by adding 32 to the ASCII value of the character.
 * *Reference: https://www.w3schools.com/charsets/ref_html_ascii.asp
 *
 * Algorithm Complexity:
 * - The toLowerCase method has a time complexity of O(n), where n is the length
 * of the input string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	string toLowerCase(string s) {
		for (auto i = 0; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
		}

		return s;
	}
};
// @lc code=end
