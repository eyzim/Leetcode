/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 *
 * @brief The implementation of the Solution class, which is used to find the
 * minimum number of bit flips required to convert a number to another number.
 *
 * Solution1:
 * - The Solution class provides a method, minBitFlips, that takes two integers,
 * start and goal, as input and returns the minimum number of bit flips required
 * to convert the start number to the goal number. The method initializes a
 * variable, ans, to 0 and iterates over the bits of the start and goal numbers.
 * For each bit, it checks if the bit is different in the start and goal numbers
 * and increments the ans variable if the bits are different. Finally, it
 * returns the ans variable.
 * Solution2:
 * - The Solution class provides a method, minBitFlips, that takes two integers,
 * start and goal, as input and returns the minimum number of bit flips required
 * to convert the start number to the goal number. The method initializes a
 * variable, n, to the XOR of the start and goal numbers and a variable, ans, to
 * 0. It then iterates over the bits of the n variable and increments the ans
 * variable for each set bit. Finally, it returns the ans variable.
 * Note that the counting bit method is similar to question 191. Number of 1
 * Bits.
 *
 * Algorithm Complexity:
 * - Both the Solution1 and Solution2 methods have a time complexity of O(log
 * n), where n is the maximum of the start and goal numbers.
 * - Both the Solution1 and Solution2 methods have a space complexity of O(1).
 */

// @lc code=start
class Solution1 {
   public:
	int minBitFlips(int start, int goal) {
		int ans = 0;

		while (start || goal) {
			// If the bits are different, increment the answer.
			if (start % 2 ^ goal % 2) {
				ans++;
			}
			start /= 2;
			goal /= 2;
		}

		return ans;
	}
};

class Solution2 {
   public:
	int minBitFlips(int start, int goal) {
		// xor will give the different bits
		int n = start ^ goal;
		int ans = 0;

		while (n) {
			ans++;
			n &= (n - 1);
		}

		return ans;
	}
};
// @lc code=end
