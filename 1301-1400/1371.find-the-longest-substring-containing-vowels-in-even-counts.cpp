/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 *
 * @brief: Given the string s, return the size of the longest substring
 * containing each vowel an even number of times.
 *
 * The solution is to use a mask to store the status of the vowels. If the mask
 * is 0, then the substring from 0 to i is a valid substring. If the mask is not
 * 0, then check if the mask is already present in the map. If the mask is
 * already present in the map, then the substring from the last occurance of the
 * mask to the current index is a valid substring. If the mask is not present in
 * the map, then add the mask to the map.
 *
 * Algorithm Complexity:
 * - Time: O(n)
 * - Space: O(n)
 */

// @lc code=start
class Solution {
   public:
	int findTheLongestSubstring(string s) {
		unordered_map<char, int> v_mp = {
			{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
		int mask = 0;
		unordered_map<int, int> mp;
		int ans = 0;

		for (auto i = 0; i < s.size(); i++) {
			// if the character is a vowel, then toggle the bit
			// ex: a -> 00001, e -> 00010, i -> 00100, o -> 01000, u -> 10000
			if (v_mp.find(s[i]) != v_mp.end()) {
				mask ^= (1 << v_mp[s[i]]);
			}

			// if the mask is 0, then the substring from 0 to i is a valid
			// substring
			if (mask == 0) {
				ans = max(ans, i + 1);
			}
			// if the mask is not 0, then check if the mask is already present
			// in the map ex: 00001, 00010, 00100, 01000, 10000
			else {
				// if the mask is already present in the map, then the substring
				// from the last occurance of the mask to the current index is a
				// valid substring
				if (mp.count(mask)) {
					ans = max(ans, i - mp[mask]);
				}
				// if the mask is not present in the map, then add the mask to
				// the map
				else {
					mp[mask] = i;
				}
			}
		}

		return ans;
	}
};
// @lc code=end
