/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * @brief Given a non-empty array of decimal digits representing a non-negative
 * integer, increment one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contains a single digit. We have
 * carry = 0 and increment the last digit by 1. If the digit is less than 10, we
 * return the array. Otherwise, we set the digit to 0 and move to the next
 * digit. We repeat this process until we reach the first digit. If we have a
 * carry, we insert it at the beginning of the array.
 *
 * Algorithm Complexity:
 * - The time complexity is O(n), where n is the number of digits in the input
 * array.
 * - The space complexity is O(1).
 */

// @lc code=start
class Solution {
   public:
	vector<int> plusOne(vector<int>& digits) {
		int pos = digits.size() - 1;
		int carry = 1;

		// Check if the digit is less than 10
		while (pos >= 0) {
			digits[pos] += carry;
			carry = 0;
			// If the digit is smaller than 10, return the array
			if (digits[pos] < 10) {
				return digits;
			}
			carry = digits[pos] / 10;
			digits[pos] %= 10;
			pos--;
		}

		if (carry) {
			digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};
// @lc code=end
