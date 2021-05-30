/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 *
 * @brief The implementation of the Solution class, which is used to sort a
 * string based on a custom order.
 *
 * The Solution class provides a method, customSortString, that takes two
 * strings as input and returns a string sorted based on the order string. The
 * method counts the frequency of each character in the input string and appends
 * the characters in the order specified in the order string.
 *
 * Algorithm Complexity:
 * - The time complexity of O(n), where n is the length of the input string.
 * - The space complexity of the customSortString method is O(n).
 */

// @lc code=start
class Solution {
   public:
	string customSortString(string order, string s) {
		unordered_map<char, int> mp;

		// count the frequency of each character in s
		for (const auto i : s) {
			mp[i]++;
		}

		string ans = "";
		// iterate through the order string and append the characters appearing
		// in s
		for (auto i : order) {
			if (mp[i]) {
				ans.append(mp[i], i);
				mp.erase(i);
			}
		}

		// append the remaining characters in the map of s
		for (const auto i : mp) {
			ans.append(i.second, i.first);
		}

		return ans;
	}
};
// @lc code=end
