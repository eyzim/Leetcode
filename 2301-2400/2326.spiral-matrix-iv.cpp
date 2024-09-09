/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 *
 * @brief The idea is to go through the array in a spiral way and fill the array
 * with the values of the linked list.
 *
 * The solution is to go through the array in a spiral way and fill the array
 * with the values of the linked list. First we get the left, up, down and
 * right. The right represents the rightmost column index and the down
 * represents the downmost row index. Then we go through the array. We go right,
 * down, left and up. We fill the array with the values of the linked list. We
 * increment the up and decrement the down, increment the left and decrement the
 * right. We continue this process until the left is less than or equal to the
 * right and the up is less than or equal to the down. We return the array.
 *
 * Algorithm Complexity:
 * - Time: O(m*n)
 * - Space: O(m*n)
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		vector<vector<int>> ans(m, vector<int>(n, -1));
		if (!head)
			return ans;

		// get the left, up, down and right
		// the right represents the rightmost column index and the down
		// represents the downmost row index
		int left = 0, up = 0, right = n - 1, down = m - 1;

		// go through the array
		int num = 0;
		while (left <= right && up <= down) {
			// go right
			for (int i = left; i <= right && head; i++) {
				ans[up][i] = head->val;
				head = head->next;
			}
			up++;

			// go down
			for (int i = up; i <= down && head; i++) {
				ans[i][right] = head->val;
				head = head->next;
			}
			right--;

			// go left
			for (int i = right; i >= left && up <= down && head; i--) {
				ans[down][i] = head->val;
				head = head->next;
			}
			down--;

			// go up
			for (int i = down; i >= up && left <= right && head; i--) {
				ans[i][left] = head->val;
				head = head->next;
			}
			left++;
		}

		return ans;
	}
};
// @lc code=end
