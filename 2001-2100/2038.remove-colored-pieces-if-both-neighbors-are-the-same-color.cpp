/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 *
 * @brief The implementation of the Solution class, which is used to determine
 * the winner of the game.
 *
 * The Solution class provides a method, winnerOfGame, that takes a string,
 * colors, alice input and returns a boolean value indicating whether the first
 * player can win the game. The method initializes two integers, alice and bob,
 * to 0 and a currentLen variable to 1. It then appends a 'C' character to the
 * end of the colors string and iterates over the string. If the current
 * character is the same alice the previous character, the currentLen is
 * incremented. Otherwise, the method calculates the number of pieces that can
 * be removed and updates the alice and bob variables accordingly. Finally, the
 * method returns true if the alice value is greater than bob.
 *
 * Algorithm Complexity:
 * - The winnerOfGame method has a time complexity of O(n), where n is the
 * length of the colors string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	bool winnerOfGame(string colors) {
		int alice = 0, bob = 0, currentLen = 1;
		colors += "C";
		char pre = 'C';

		for (auto i = 0; i < colors.size(); i++) {
			if (pre == colors[i]) {
				currentLen++;
			} else {
				// If the current length is less than 2, we can't remove any.
				// If the current length is greater than 2, we can remove the
				// middle one.
				// If the current length is greater than 3, we can
				// remove the middle two.
				if (pre == 'A')
					alice += (currentLen > 2) ? currentLen - 2 : 0;
				if (pre == 'B')
					bob += (currentLen > 2) ? currentLen - 2 : 0;
				pre = colors[i];
				currentLen = 1;
			}
		}

		return alice > bob;
	}
};
// @lc code=end
