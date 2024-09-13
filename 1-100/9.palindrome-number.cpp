/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * @brief The implementation of the Solution class, which is used to determine
 * if a number is a palindrome.
 *
 * The Solution class provides a method, isPalindrome, that takes an integer, x,
 * as input and returns a boolean value indicating whether x is a palindrome.
 * The method first checks if x is negative or less than 10 and returns false or
 * true, respectively. It then initializes two long integers, before and after,
 * to x and 0, respectively. It then iterates through the digits of x, updating
 * after with the reversed digits. Finally, it returns whether x is equal to
 * after.
 *
 * Algorithm Complexity:
 * - The isPalindrome method has a time complexity of O(log(x)), where x is the
 * input integer.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		else if (x < 10)
			return true;

		long int before = x, after = 0;

		while (before) {
			after = 10 * after + (before % 10);
			before /= 10;
		}

		return x == after;
	}
};
// @lc code=end
