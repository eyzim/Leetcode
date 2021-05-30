/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 *
 * @brief The implementation of the Solution class, which is used to calculate
the XOR of a range of numbers.
 *
 * The class leverages properties of XOR to efficiently compute the XOR of a
 * series without needing to explicitly generate it. It breaks down the problem
 * into smaller, manageable parts:
 * Using xor_n(int n) to get the XOR for ranges.
 * Simplifying the series by halving and considering the structure created by
 * even-odd combinations. Adjusting for the series pattern using multiplication
 * and addition based on parity.
 *
 * Algorithm Complexity:
 * - The xorOperation method has a time complexity of O(1).
 * - The space complexity of the xorOperation method is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	int xorOperation(int n, int start) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans ^= (start + 2 * i);
		}

		return ans;
	}
};

class Solution2 {
   private:
	int xor_n(int n) {
		switch (n % 4) {
			case 0:
				return n;  // XOR from 0 to n when n % 4 == 0
			case 1:
				return 1;  // XOR from 0 to n when n % 4 == 1
			case 2:
				return n + 1;  // XOR from 0 to n when n % 4 == 2
			default:
				return 0;  // XOR from 0 to n when n % 4 == 3
		}
	}

   public:
	int xorOperation(int n, int start) {
		int a = start / 2;

		/*
		start & 1 checks if start is odd (1 if odd, 0 if even).
		n & 1 checks if n is odd (1 if odd, 0 if even).
		n & start & 1 checks if both n and start are odd, resulting in b being 1
		if both are odd, otherwise 0.
		*/

		int b = n & start & 1;

		/*
		xor_n(a + n - 1) ^ xor_n(a - 1): This part calculates the XOR of the
		range [a, a + n - 1].

		xor_n(a + n - 1) gives XOR from 0 to a + n - 1.
		xor_n(a - 1) gives XOR from 0 to a - 1.
		XORing these two gives the XOR of the numbers between a and a + n - 1.
		* 2: This multiplies the result by 2 to account for the fact that our
		series increments by 2 (i.e., start + 2 * i).

		+ b: This adjusts the result by adding b, which is 1 if both n and start
		are odd, otherwise 0.
		*/
		return (xor_n(a + n - 1) ^ xor_n(a - 1)) * 2 + b;
	}
};
// @lc code=end
