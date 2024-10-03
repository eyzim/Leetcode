/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * @brief The implementation of the Solution class, which is used to reverse a
 * string.
 *
 * The Solution class provides a method, reverseString, that takes a vector of
 * characters as input and reverses the string in place. We can reverse the
 * string by swapping the characters from the beginning and the end of the
 * string until we reach the middle of the string.
 *
 * Algorithm Complexity:
 * - The reverseString method has a time complexity of O(n), where n is the size
 * of the input array.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	void reverseString(vector<char>& s) {
		int size = s.size();
		for (auto i = 0; i < size >> 1; i++) {
			swap(s[i], s[size - 1 - i]);
		}
	}
};
// @lc code=end
