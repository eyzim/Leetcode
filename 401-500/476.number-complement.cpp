/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * @brief The implementation of the Solution class, which is used to find the
 * complement of a number.
 *
 * The Solution class provides a method, findComplement, that takes an integer
 * num as input and returns the complement of the number. The complement of a
 * number is the bitwise complement of the number.
 *
 * Example:
 * 1. making the mask:
 *  0000 0000 0000 0000 0000 0000 0000 0101 ----> num
 *                                            => bits = floor(log2(num)) + 1 = 3
 *  0000 0000 0000 0000 0000 0000 0000 1000 ----> (1 << bits)
 *  0000 0000 0000 0000 0000 0000 0000 0111 ----> (1 << bits) - 1
 *                                             => mask = (1 << bits) - 1
 *
 * 2. num XOR mask:
 *   0000 0000 0000 0000 0000 0000 0000 0101 ----> num
 *   0000 0000 0000 0000 0000 0000 0000 0111 ----> mask
 * ------------------------------------------------------------
 *   0000 0000 0000 0000 0000 0000 0000 0010 ----> num XOR mask
 *
 *
 * Algorithm Complexity:
 * - The findComplement method has a time complexity of O(1), as we perform a
 * constant number of operations to find the complement of the number.
 * - The space complexity of the findComplement method is O(1), as we use a
 * constant amount of space to store the result.
 */

// @lc code=start
class Solution {
   public:
	int findComplement(int num) {
		// Find the number of bits required to represent the number.
		unsigned int bits = floor(log2(num)) + 1;

		return (unsigned int)((1 << bits) - 1) ^ num
	}
};
// @lc code=end
