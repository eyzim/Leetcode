/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * @brief Find the longest palindromic substring in a string.
 *
 * The idea is to iterate through the string and check if the substring s[i:j]
 * is a palindrome. We can do this by walking towards the leftmost and rightmost
 * characters of the substring. We can check for both odd and even length
 * palindromes. We can use a priority queue to store the length of the
 * palindromes and the start index from longest length to smallest length.
 * There's a trick to handle the start index of the substring in the same length
 * in the priority queue. We can use the start index of the substring to
 * calculate the start index of the palindrome substring.
 *
 * Algorithm Complexity:
 * - Time complexity: O(n^2)
 * - Space complexity: O(n)
 */

// @lc code=start
class Solution {
   private:
	// Check if the substring s[i:j] is a palindrome.
	// O(n) time complexity.
	int checkPalindromeLen(string& s, int i, int j) {
		int len = 0;

		// if the characters at i and j are equal, keep walking towards the
		// leftmost and rightmost characters
		while (i >= 0 && j < s.size() && s[i] == s[j]) {
			i--;
			j++;
			len += 2;
		}

		return len;
	}

   public:
	string longestPalindrome(string s) {
		if (s.size() == 1)
			return s;

		// Priority queue to store the length of the palindromes and the start
		// index from longest length to smallest length.
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			pq;

		for (int i = 0; i < s.size(); i++) {
			// Odd length palindromes
			int len = checkPalindromeLen(s, i, i) - 1;
			pq.push({-len, i - len / 2});

			// Even length palindromes
			len = checkPalindromeLen(s, i, i + 1);
			pq.push({-len, i - len / 2 + 1});
		}

		string ans = "";
		if (!pq.empty()) {
			ans = s.substr(pq.top().second, -pq.top().first);
		} else {
			ans = s[0];
		}

		return ans;
	}
};
// @lc code=end
