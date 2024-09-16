/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 *
 * @brief The implementation of the Solution class, which is used to find the
 * number of different integers in a string.
 *
 * The Solution class provides a method, numDifferentIntegers, that takes a
 * string, word, as input and returns the number of different integers in the
 * string. First, it initializes an unordered_set of strings, mp, to store the
 * different integers. It then appends a character 'a' to the end of the string
 * to ensure that the last integer is added to the set. It then iterates through
 * the string and adds the digits to a string w. If w is not empty, it removes
 * leading zeros and adds it to the set. Finally, it returns the size of the
 * set, which is the number of different integers.
 *
 * Algorithm Complexity:
 * - The numDifferentIntegers method has a time complexity of O(n), where n is
 * the length of the string.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	int numDifferentIntegers(string word) {
		unordered_set<string> mp;

		word += "a";
		string w = "";
		for (auto i : word) {
			// if i is a digit, then add it to w
			if (isdigit(i)) {
				w += i;
				continue;
			}

			// if w is not empty, then insert it into the set
			if (w.size()) {
				// remove leading zeros
				while (w[0] == '0') {
					w.erase(0, 1);
				}
				mp.insert(w);
				w.clear();
			}
		}

		// return the size of the set, which is the number of different integers
		return mp.size();
	}
};
// @lc code=end
