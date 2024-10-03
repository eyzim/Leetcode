/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * @brief Given the head of a singly linked list, reverse the list, and return
 * the reversed list.
 *
 * The idea is to reverse the linked list iteratively. We can use three pointers
 * to reverse the linked list. For each node, we need to store the next node and
 * the previous node. We can reverse the linked list by setting the current
 * node's next to the previous node. Then, we can update the previous node to
 * the current node and the current node to the next node.
 *
 * Algorithm Complexity:
 * - Time complexity: O(n)
 * - Space complexity: O(1)
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
	ListNode* reverseList(ListNode* head) {
		ListNode *cur = head, *n, *pre = NULL;

		while (cur) {
			n = cur->next;
			cur->next = pre;

			pre = cur;
			cur = n;
		}

		return pre;
	}
};
// @lc code=end
