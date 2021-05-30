/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * @brief The implementation of the Solution class, which is used to defang an
 * IPv4 address.
 *
 * The Solution class provides a method, defangIPaddr, that takes a string
 * representing an IPv4 address as input and returns the defanged version of the
 * address. The method iterates through the input string and replaces each '.'
 * character with '[.]'. The defanged address is then returned as the output.
 *
 * Algorithm Complexity:
 * - The defangIPaddr method has a time complexity of O(n), where n is the
 * length of the input string.
 * - The space complexity of the method is O(n), where n is the length of the
 * input string.
 */

// @lc code=start
class Solution {
   public:
	string defangIPaddr(string address) {
		string ans = "";
		for (auto i = 0; i < address.size(); i++) {
			if (address[i] == '.') {
				ans += "[.]";
			} else {
				ans += address[i];
			}
		}

		return ans;
	}
};
// @lc code=end
