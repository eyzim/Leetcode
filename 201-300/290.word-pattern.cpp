/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * @brief The implementation of the Solution class, which is used to check if a
 * given pattern matches a string.
 *
 * The Solution class provides a method, wordPattern, that takes a pattern
 * string and a string s as input and returns a boolean value indicating whether
 * the pattern matches the string. The method splits the string s into words and
 * checks if the pattern and words match each other. It uses two hash maps to
 * store the mapping between the pattern and words and vice versa. If the
 * pattern and words do not match, the method returns false; otherwise, it
 * returns true.
 *
 * Algorithm Complexity:
 * - The wordPattern method has a time complexity of O(n), where n is the number
 * of words in the input string s.
 * - The space complexity of the method is O(n), where n is the number of words
 * in the input string s.
 */

// @lc code=start
class Solution {
   public:
	bool wordPattern(string pattern, string s) {
		// split the string s into words
		s.append(1, ' ');
		vector<string> words;
		string t = "";
		for (auto i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				words.push_back(t);
				t = "";
			} else {
				t += s[i];
			}
		}

		// check if the size of pattern and words are the same
		if (pattern.size() != words.size())
			return false;

		// 1. pattern -> words
		unordered_map<string, char> mp1;
		for (auto i = 0; i < words.size(); i++) {
			if (mp1.find(words[i]) != mp1.end() &&
				mp1[words[i]] != pattern[i]) {
				return false;
			}
			mp1[words[i]] = pattern[i];
		}

		// 2. words -> pattern
		unordered_map<char, string> mp2;
		for (auto i = 0; i < pattern.size(); i++) {
			if (mp2.find(pattern[i]) != mp2.end() &&
				mp2[pattern[i]] != words[i]) {
				return false;
			}
			mp2[pattern[i]] = words[i];
		}

		return true;
	}
};
// @lc code=end
