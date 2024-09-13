/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 *
 * @brief The implementation of the Solution class, which is used to find the
 * difference between two strings.
 *
 * 1. Solution1:
 * - The Solution1 class implements the findTheDifference method to find the
 * difference between two strings.
 * - It uses an unordered_map to store the frequency of characters in the first
 * string.
 * - It then iterates through the second string and decrements the frequency of
 * characters in the map.
 * - If a character is not found in the map or its frequency is zero, it returns
 * the character as the difference.
 * 2. Solution2:
 * - The Solution2 class implements the findTheDifference method to find the
 * difference between two strings.
 * - It sorts both strings and compares them character by character.
 * - If a character is different, it returns the character as the difference.
 * 3. Solution3:
 * - The Solution3 class implements the findTheDifference method to find the
 * difference between two strings.
 * - It calculates the difference between the ASCII values of the characters in
 * the two strings.
 * - The difference is the ASCII value of the extra character.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The findTheDifference method has a time complexity of O(n), where n is the
 * length of the second string.
 * - The space complexity of the method is O(n).
 * 2. Solution2:
 * - The findTheDifference method has a time complexity of O(nlogn), where n is
 * the length of the second string.
 * - The space complexity of the method is O(1).
 * 3. Solution3:
 * - The findTheDifference method has a time complexity of O(n), where n is the
 * length of the second string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start

// Using unordered_map
class Solution1 {
   public:
	char findTheDifference(string s, string t) {
		unordered_map<char, int> mp;
		for (auto i : s) {
			mp[i]++;
		}

		char ans;

		for (auto i : t) {
			if (mp[i]) {
				mp[i]--;
			} else {
				ans = i;
				break;
			}
		}

		return ans;
	}
};

// Using sorting and comparing one by one
class Solution2 {
   public:
	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		for (auto i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				return t[i];
			}
		}

		return t.back();
	}
};

// Using ASCII values
class Solution3 {
   public:
	char findTheDifference(string s, string t) {
		int ans = 0;

		for (auto i = 0; i < s.size(); i++) {
			ans -= s[i];
			ans += t[i];
		}
		ans += t.back();

		return char(ans);
	}
};
// @lc code=end
