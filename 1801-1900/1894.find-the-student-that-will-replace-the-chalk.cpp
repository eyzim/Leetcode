/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 *
 * @brief The implementation of the Solution class, which is used to find the
 * student that will not get enough chalks.
 *
 * The Solution class provides a method, chalkReplacer, that takes a vector of
 * integers representing the number of chalks each student has and an integer k
 * representing the number of chalks needed by the students. The method returns
 * the index of the student who will not get enough chalks. The method first
 * calculates the total sum of chalks and checks if the students can get only
 * one turn of chalks. If so, the method returns the index of the student. If
 * the students can get more than one turn of chalks, the method finds the
 * remainder of chalks and returns the index of the student who will replace the
 * chalk.
 *
 * Algorithm Complexity:
 * - The chalkReplacer method has a time complexity of O(n), where n is the
 * number of students. The method iterates through the students to find the
 * student who will replace the chalk.
 * - The space complexity of the method is O(1). The method uses a constant
 * amount of extra space.
 */

// @lc code=start
class Solution {
   public:
	int chalkReplacer(vector<int>& chalk, int k) {
		// 1. Find the total sum of chalks
		int sum = 0;
		for (auto i = 0; i < chalk.size(); i++) {
			sum += chalk[i];
			// 2. If those students can only get one turn of chalks, return the
			// index of the student
			if (sum > k)
				return i;
		}

		// 3. If the students can get more than one turn of chalks, find the
		// remainder of chalks
		k %= sum;

		// 4. Find the student who will replace the chalk
		if (k == 0)
			return 0;
		for (auto i = 0; i < chalk.size(); i++) {
			if (k < chalk[i])
				return i;
			k -= chalk[i];
		}

		return 0;
	}
};
// @lc code=end
