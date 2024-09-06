/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of 1 bits in the binary representation of each number from 0 to n.
 *
 * In solution 1, the countBits method generates the answer by iterating over
 * the sequence of numbers from 0 to n and counting the number of 1 bits in each
 * number. The method uses a vector to store the answer and calculates the
 * number of 1 bits using the formula ans[i] = ans[i / 2] + (i % 2).
 * // one bit group
 *  0=   0(0)
 *  1=   1(1)
 * // two bits group
 *  2=  10(1) = 10(higest bit) + 0
 *  3=  11(2) = 10 + 1
 * // three bits group
 *  4= 100(1) = 100(higest bit) + 0
 *  5= 101(2) = 100 + 1
 *  6= 110(2) = 100 + 2
 *  7= 111(3) = 100 + 3
 * // four bits group
 *  8=1000(1)=1000(higest bit) + 0
 *  9=1001(2) = 1000 + 1
 * 10=1010(2) = 1000 + 2
 * 11=1011(3) = 1000 + 3
 * 12=1100(2) = 1000 + 4
 * 13=1101(3) = 1000 + 5
 * 14=1110(3) = 1000 + 6
 * 15=1111(4) = 1000 + 7
 * // five bits group
 * 16=10000(1)
 *
 * In solution 2, the countBits method generates the answer by iterating over
 * the sequence of numbers from 0 to n and counting the number of 1 bits in each
 * number. The method uses a vector to store the answer and calculates the
 * number of 1 bits using the formula ans[i] = ans[i / 2] if i is even,
 * and ans[i] = ans[i - 1] + 1 if i is odd.
 *
 * Algorithm Complexity:
 * - The time complexity of both solutions is O(n), where n is the input number.
 * - The space complexity of both solutions is O(n), where n is the input
 * number.
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> countBits(int n) {
		vector<int> ans = {0, 1};

		int powerOfTwo = 1;
		// 1, 2, 4, 8, 16, 32, 64, 128, 256, 512
		while (powerOfTwo <= n) {
			powerOfTwo *= 2;
			for (auto i = 0; i < powerOfTwo; i++) {
				ans.push_back(ans[i] + 1);
			}
		}

		// erase the elements after n
		ans.erase(ans.begin() + n + 1, ans.end());

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> countBits(int n) {
		if (!n)
			return {0};

		vector<int> ans(n + 1, 0);
		ans[1] = 1;

		for (auto i = 0; i <= n; i++) {
			if (i % 2 == 0) {
				ans[i] = ans[i / 2];
			} else {
				ans[i] = ans[i - 1] + 1;
			}
		}

		return ans;
	}
};
// @lc code=end
