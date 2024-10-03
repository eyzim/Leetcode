/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * @brief The implementation of the Solution class, which is used to find the
 * length of the last word in a string.
 *
 * The implementation of the lengthOfLastWord method using two pointers. The
 * method first finds the end point of the last word by iterating from the end
 * of the string to the start and skipping any trailing spaces. If the end is 0,
 * the method returns 1. The method then finds the start point of the last word
 * by iterating from the end to the start and skipping any characters that are
 * not spaces. Finally, the method returns the length of the last word by
 * subtracting the start from the end.
 *
 * Algorithm Complexity:
 * - The lengthOfLastWord method has a time complexity of O(n), where n is the
 * number of characters in the string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int lengthOfLastWord(string s) {
		// find the end point of the last word
		int end = s.size() - 1;
		while (end >= 0 && s[end] == ' ') {
			end--;
		}
		// if the end is 0, then the last word is the only word, so return 1
		if (end == 0)
			return 1;

		// find the start point of the last word
		int start = end;
		while (start >= 0 && s[start] != ' ') {
			start--;
		}

		return end - start;
	}
};
// @lc code=end
