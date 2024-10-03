/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the minimum number of operations to move all balls to each box.
 * You have n boxes. You are given a binary string boxes of length n, where
 * boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
 *
 * In solution 1, we calculate the minimum number of operations to move all
 * balls to each box. We first calculate the prefix sum of the boxes. Then we
 * iterate through the boxes and calculate the minimum number of operations for
 * each box. The time complexity of this solution is O(n), where n is the number
 * of boxes.
 * In solution 2, we calculate the minimum number of operations to move all
 * balls to each box. We first count the weight of the balls on the right side.
 * Then we iterate through the boxes and calculate the minimum number of
 * operations for each box. The time complexity of this solution is O(n), where
 * n is the number of boxes.
 *
 * Algorithm Complexity:
 * - The time complexity of both solutions is O(n), where n is the number of
 * boxes.
 * - The space complexity of both solutions is O(n), where n is the number of
 * boxes.
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> minOperations(string boxes) {
		int pre = 0, sum = 0;
		vector<int> prefix(boxes.size(), 0);

		for (int i = 0; i < boxes.size(); i++) {
			int b = (boxes[i] - '0');
			if (b == 1) {
				pre += i;
				sum++;
			}
			prefix[i] = sum;
		}

		vector<int> ans(boxes.size(), pre);
		for (int i = 1; i < ans.size(); i++) {
			// ans[i] = ans[i-1] - (prefix[i]-prefix[i-1]) + (prefix[i-1]) -
			// (sum-prefix[i]);
			ans[i] = ans[i - 1] + (2 * prefix[i - 1]) - sum;
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> minOperations(string boxes) {
		vector<int> ans(boxes.size());

		// Count the weight of the balls of the right side.
		int count = 0, op = 0;
		for (int i = 0; i < ans.size(); i++) {
			ans[i] += op;
			count += (boxes[i] == '1') ? 1 : 0;
			op += count;
		}

		// Count the weight of the balls of the left side.
		count = 0, op = 0;
		for (int i = ans.size() - 1; i >= 0; i--) {
			ans[i] += op;
			count += (boxes[i] == '1') ? 1 : 0;
			op += count;
		}

		return ans;
	}
};
// @lc code=end
