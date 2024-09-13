/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of consistent strings.
 * The consistent strings are those that contain only characters present in the
 * allowed string. Otherwise, if the string contains any character not present
 * in the allowed string, it is not consistent.
 *
 * The Solution class provides a method, countConsistentStrings, that takes a
 * string, allowed, and a vector of strings, words, as input and returns the
 * number of consistent strings. First, it initializes an unordered_set, mp, and
 * inserts each character of the allowed string into it. It then initializes an
 * integer, ans, to 0 and iterates through each word in the words vector. For
 * each word, it checks if all the characters are present in the mp set. If they
 * are, it increments the ans variable. Finally, it returns the ans variable.
 *
 * Algorithm Complexity:
 * - The countConsistentStrings method has a time complexity of O(n*m), where n
 * is the number of words in the words vector and m is the average length of the
 * words.
 * - The space complexity of the method is O(k), where k is the number of unique
 * characters in the allowed string.
 */

// @lc code=start
class Solution {
   public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		unordered_set<char> mp;
		for (auto i : allowed) {
			mp.insert(i);
		}

		int ans = 0;
		for (auto word : words) {
			bool cnt = true;
			for (auto i : word) {
				// If the character is not present in the allowed string, break
				// the loop. Cause the word is not consistent.
				if (!mp.count(i)) {
					cnt = false;
					break;
				}
			}

			if (cnt)
				ans++;
		}

		return ans;
	}
};
// @lc code=end
