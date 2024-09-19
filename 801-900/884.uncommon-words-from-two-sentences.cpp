/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 *
 * @brief Print the words which are unique in both the strings s1 and s2 and
 * only occur once.
 *
 * The Solution1 uses two loops to go through the strings s1 and s2 and then get
 * the count of each word. The Solution2 uses only one loop to go through the
 * concatenated string of s1 and s2.
 *
 * Algorithm Complexity:
 * - Time: O(n)
 * - Space: O(n)
 */

// @lc code=start
// Using two loops
class Solution1 {
   public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		s1 += " ";
		s2 += " ";

		unordered_map<string, int> mp;

		// Go through s1
		string word = "";
		for (auto i = 0; i < s1.size(); i++) {
			if (s1[i] == ' ' && word.size()) {
				mp[word]++;
				word = "";
				continue;
			}
			word += s1[i];
		}

		// Go through s2
		word = "";
		for (auto i = 0; i < s2.size(); i++) {
			if (s2[i] == ' ' && word.size()) {
				mp[word]++;
				word = "";
				continue;
			}
			word += s2[i];
		}

		// Get the words which are unique
		vector<string> ans;
		for (const auto& i : mp) {
			if (i.second == 1) {
				ans.push_back(i.first);
			}
		}

		return ans;
	}
};

// Without using two loops
class Solution2 {
   public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		// Concatenate the strings
		s1 = s1 + " " + s2 + " ";

		unordered_map<string, int> mp;

		// Go through s1 (s1 + s2)
		string word = "";
		for (auto i = 0; i < s1.size(); i++) {
			if (s1[i] == ' ' && word.size()) {
				mp[word]++;
				word = "";
				continue;
			}
			word += s1[i];
		}

		vector<string> ans;
		for (const auto& i : mp) {
			if (i.second == 1) {
				ans.push_back(i.first);
			}
		}

		return ans;
	}
};
// @lc code=end
