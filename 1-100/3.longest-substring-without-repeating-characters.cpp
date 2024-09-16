/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * @brief Find the length of the longest substring without repeating characters.
 *
 * 1. Solution 1: Brute force
 * The idea is to check all the substrings of the given string and find the
 * length of the substring without repeating characters. First, we need to check
 * if the substring has repeating characters. If not, we can update the maximum
 * length of the substring. In solution 1, we use a set to store the characters
 * of the substring. If the size of the set is equal to the size of the
 * substring, it means that there are no repeating characters in the substring.
 * The time complexity of this solution is O(n^3).
 *
 * 2. Solution 2: Sliding window
 * The idea is to use a sliding window to find the length of the longest
 * substring without repeating characters. We can use a hash map to store the
 * index of the characters in the string. We also need two pointers, start and
 * end, to represent the start and end of the substring. If the character is
 * already in the map, we need to update the start index. The time complexity of
 * this solution is O(n). First, we initialize the maximum length of the
 * substring to 0 and the start index to 0. Then, we iterate through the string.
 * If the character is already in the map, we update the start index to the
 * previous index+1 of the character. We also update the maximum length of the
 * substring. Finally, we return the maximum length of the substring.
 * For example, the input string is "abcabcbb". The maximum length of the
 * substring is 3.
 * - start = 0, end = 0, mp = {}, maxi = 0
 * - start = 0, end = 1, mp = {a: 1}, maxi = 1
 * - start = 0, end = 2, mp = {a: 1, b: 2}, maxi = 2
 * - start = 0, end = 3, mp = {a: 1, b: 2, c: 3}, maxi = 3
 * - start = 1, end = 4, mp = {a: 4, b: 2, c: 3}, maxi = 3
 * - start = 2, end = 5, mp = {a: 4, b: 5, c: 3}, maxi = 3
 * - start = 3, end = 6, mp = {a: 4, b: 5, c: 6}, maxi = 3
 * - start = 5, end = 7, mp = {a: 4, b: 7, c: 6}, maxi = 3
 *
 * Algorithm Complexity:
 * 1. Solution 1
 * - Time complexity: O(n^3)
 * - Space complexity: O(n)
 * 2. Solution 2
 * - Time complexity: O(n)
 * - Space complexity: O(n)
 */

// @lc code=start
class Solution1 {
   private:
	int withoutRepeat(string s) {
		set<char> mp(s.begin(), s.end());
		return mp.size() == s.size() ? mp.size() : 0;
	}

   public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;

		int ans = 1;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= s.size(); j++) {
				// Check all the substrings of the given string
				int len = withoutRepeat(s.substr(i, j));
				if (len > 0) {
					ans = max(ans, len);
				} else {
					break;
				}
			}
		}

		return ans;
	}
};

class Solution {
   public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> mp;
		int maxi = 0;
		int start = 0;

		for (int end = 0; end < s.size(); end++) {
			// if the character is already in the map, update the start index
			if (mp[s[end]]) {
				start = max(start, mp[s[end]]);
			}

			// if we need to search the existing character in the map, we
			// need to add 1 to the index
			mp[s[end]] = end + 1;

			// update the maximum length
			maxi = max(maxi, end - start + 1);
		}

		return maxi;
	}
};
// @lc code=end
