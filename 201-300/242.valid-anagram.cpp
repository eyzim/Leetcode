/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * @brief The implementation of the Solution class, which is used to check if
 * two strings are anagrams of each other.
 *
 * The Solution class provides a method, isAnagram, that takes two strings as
 * input and returns a boolean value representing whether the two strings are
 * anagrams of each other. The method first checks if the size of the two
 * strings is different. If the size is different, the method returns false. The
 * method then uses an unordered map to count the frequency of each character in
 * the first string. It then iterates through the second string and checks if
 * the character exists in the map. If the character does not exist, the method
 * returns false. If the character exists, the method decrements the count in
 * the map. The method returns true if the second string is an anagram of the
 * first string.
 *
 * Algorithm Complexity:
 * - The isAnagram method has a time complexity of O(n), where n is the size of
 * the input strings.
 * - The space complexity of the method is O(n), where n is the size of the
 * input strings.
 */

// @lc code=start
class Solution {
   public:
	bool isAnagram(string s, string t) {
		// If the size of the two strings is different, they cannot be anagrams
		if (s.size() != t.size())
			return false;

		unordered_map<int, int> mp;

		// Count the frequency of each character in the first string
		for (auto i : s) {
			mp[i]++;
		}

		// Check if the second string is an anagram of the first string
		for (auto i : t) {
			if (!mp[i]) {
				return false;
			}
			mp[i]--;
		}

		return true;
	}
};
// @lc code=end
