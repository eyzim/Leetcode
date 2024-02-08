/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
   public:
	unsigned long long inputToNumbString(string& s) {
		unordered_map<char, int> mp;
		int cur = 0;
		unsigned long long ret = 0;

		for (int i = 0; i < s.length(); i++) {
			if (!mp[s[i]]) {
				mp[s[i]] = ++cur;
			}
			ret = ret * 10 + mp[s[i]];
		}

		return ret;
	}

	bool isIsomorphic(string s, string t) {
		return inputToNumbString(s) == inputToNumbString(t);
	}
};
// @lc code=end
