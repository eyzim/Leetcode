/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * @brief The implementation of the Solution class, which is used to remove all
 * elements from a linked list of integers that have a specified value.
 *
 * The Solution class provides a method, removeElements, that takes a ListNode
 * pointer, head, and an integer, val, as input and returns the head of the
 * linked list with all elements that have the specified value removed. The
 * method creates a dummy node, pre, and sets its next pointer to the head of
 * the linked list. It then iterates through the linked list, removing any
 * elements that have the specified value. Finally, it returns the next pointer
 * of the dummy node.
 *
 * Algorithm Complexity:
 * - The removeElements method has a time complexity of O(n), where n is the
 * number of elements in the linked list.
 * - The space complexity of the method is O(1).
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* pre = new ListNode();
		pre->next = head;
		ListNode* cur = pre;

		while (cur->next) {
			// If the next node has the specified value, remove it
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			// Otherwise, move to the next node
			else {
				cur = cur->next;
			}
		}

		return pre->next;
	}
};
// @lc code=end
