/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 *
 * @brief The implementation of the Solution class, which is
 * used to reverse the prefix of a word.
 *
 * The Solution class provides a method, reversePrefix, that takes a word and a
 * character as input and returns the word with its prefix reversed up to the
 * given character. The reverseString method is a private helper function that
 * reverses a given string.
 *
 * Algorithm Complexity:
 * - The reverseString method has a time complexity of O(n), where n is the
 * length of the input string.
 * - The reversePrefix method has a time complexity of O(n), where n is the
 * length of the input word.
 * - The space complexity of both methods is O(1).
 */

// @lc code=start
class Solution {
   private:
	string reverseString(string str) {
		int l = 0, r = str.size() - 1;
		while (l < r) {
			char temp = str[l];
			str[l] = str[r];
			str[r] = temp;
			l++;
			r--;
		}

		return str;
	}

   public:
	string reversePrefix(string word, char ch) {
		if (word.size() == 1)
			return word;

		// find the position of ch
		int pos = 0;
		for (auto i = 0; i < word.size(); i++) {
			if (word[i] == ch) {
				pos = i;
				break;
			}
		}

		// reverse the string and combine with the remaining string
		return reverseString(word.substr(0, pos + 1)) +
			   word.substr(pos + 1, word.size() - pos);
	}
};
// @lc code=end