/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * @brief The implementation of the Solution class, which is used to find the
 * smallest letter in the list that is greater than the target.
 *
 * The first solution uses a binary search algorithm to find the smallest letter
 * in the list that is greater than the target. The algorithm initializes two
 * pointers, left and right, to 0 and the size of the list minus one,
 * respectively. It then iterates through the list until the left pointer is
 * less than or equal to the right pointer. In each iteration, it calculates the
 * middle index and compares the middle element with the target. If the middle
 * element is greater than the target, it updates the right pointer to mid - 1;
 * otherwise, it updates the left pointer to mid + 1. Finally, it returns the
 * element at the left pointer.
 * The second solution uses a linear search algorithm to find the smallest
 * letter in the list that is greater than the target. The algorithm iterates
 * through the list and returns the first element that is greater than the
 * target. If no such element is found, it returns the first element in the
 * list.
 *
 * Algorithm Complexity:
 * - The first solution has a time complexity of O(log n), where n is the size
 * of the list.
 * - The second solution has a time complexity of O(n).
 * - Both solutions have a space complexity of O(1).
 */

// @lc code=start

class Solution1 {
   public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		if (letters.back() <= target)
			return letters.front();

		int left = 0, right = letters.size() - 1;

		while (left <= right) {
			int mid = left + ((right - left) >> 1);

			if (letters[mid] > target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		return letters[left];
	}
};

class Solution2 {
   public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		for (auto i : letters) {
			if (target < i) {
				return i;
			}
		}

		return letters[0];
	}
};
// @lc code=end
