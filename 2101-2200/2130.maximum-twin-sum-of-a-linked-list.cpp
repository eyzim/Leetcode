/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum sum of twin pairs in a linked list.
 *
 * The Solution class provides a method, pairSum, that takes a ListNode pointer,
 * head, as input and returns the maximum sum of twin pairs in the linked list.
 * First, it initializes a stack, st, to store the values of the first half of
 * the linked list. It then finds the middle of the linked list using the slow
 * and fast pointers. It then checks the maximum sum of the twin pair by
 * iterating through the second half of the linked list and comparing the sum of
 * the current node and the top of the stack with the maximum sum. Finally, it
 * returns the maximum sum of the twin pairs.
 *
 * Algorithm Complexity:
 * - The pairSum method has a time complexity of O(n), where n is the number of
 * nodes in the linked list.
 * - The space complexity of the method is O(n).
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
	int pairSum(ListNode* head) {
		stack<int> st;

		// find the middle of the linked list
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			st.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}

		// check the maximum sum of the twin pair
		int maxi = 0;
		while (slow && !st.empty()) {
			maxi = max(maxi, slow->val + st.top());
			slow = slow->next;
			st.pop();
		}

		return maxi;
	}
};
// @lc code=end
