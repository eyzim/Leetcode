/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * @brief The implementation of the Solution class, which is used to reverse the
 * bits of a 32-bit unsigned integer.
 *
 * The Solution class provides a method, reverseBits, that takes an unsigned
 * integer, n, as input and returns the integer with the bits reversed. For
 * example, if the input is 00000010100101000001111010011100, the output should
 * be 00111001011110000010100101000000. First, the method initializes a
 * variable, ans, to store the result. Then, it iterates over the 32 bits of the
 * input integer, shifting the bits to the left in the ans variable and adding
 * the last bit of the input integer to the ans variable. Finally, it returns
 * the reversed integer.
 *
 * Algorithm Complexity:
 * - The reverseBits method has a time complexity of O(1).
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	uint32_t reverseBits(uint32_t n) {
		int ans = 0;

		for (int i = 0; i < 32; i++) {
			// left shift ans by 1 and add the last bit of n
			ans <<= 1;
			ans |= (n & 1);
			// right shift n by 1
			n >>= 1;
		}

		return ans;
	}
};
// @lc code=end
