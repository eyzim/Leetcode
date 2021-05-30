/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * @brief The implementation of the Solution class, which is used to find the
 * common characters in a list of words.
 *
 * The Solution class provides a method, commonChars, that takes a vector of
 * strings as input and returns a vector of strings containing the common
 * characters among all the words. The findCommoninTwo method is a private
 * helper function that finds the common characters between two strings.
 *
 * Algorithm Complexity:
 * - The findCommoninTwo method has a time complexity of O(n), where n is the
 * length of the input string.
 * - The commonChars method has a time complexity of O(n*m), where n is the
 * number of words and m is the average length of the words.
 * - The space complexity of both methods is O(1).
 */

// @lc code=start
class Solution {
   private:
	string findCommoninTwo(string s1, string s2) {
		unordered_map<char, int> mp;

		for (const auto i : s2) {
			mp[i]++;
		}

		// Find the common characters between two strings
		string n = "";
		for (auto i : s1) {
			if (mp[i] > 0) {
				n += i;
				mp[i]--;
			}
		}

		return n;
	}

   public:
	vector<string> commonChars(vector<string>& words) {
		string temp = words[0];
		vector<string> ans;

		for (auto i : words) {
			temp = findCommoninTwo(temp, i);
		}

		// Convert the string to a vector of strings
		for (auto i : temp) {
			ans.push_back(string(1, i));
		}

		return ans;
	}
};
// @lc code=end
