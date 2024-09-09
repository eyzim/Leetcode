/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * @brief The implementation of the Solution class, which is used to remove
 * duplicates from a sorted list.
 *
 * The Solution class provides a method, deleteDuplicates, that takes a ListNode
 * pointer, head, as input and removes duplicates from the sorted list. It
 * initializes a ListNode pointer, cur, to head and an integer, v, to the value
 * of cur. It then iterates through the list, updating the value of v and cur
 * accordingly. If the value of cur is equal to the value of the next node, it
 * removes the next node; otherwise, it updates the value of v and moves to the
 * next node. Finally, it returns the head of the list.
 *
 * Algorithm Complexity:
 * - The deleteDuplicates method has a time complexity of O(n), where n is the
 * number of nodes in the list.
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;

		ListNode* cur = head;
		int v = cur->val;

		while (cur->next) {
			int t = cur->next->val;
			if (v == t) {
				cur->next = cur->next->next;
			} else {
				v = t;
				cur = cur->next;
			}
		}

		return head;
	}
};
// @lc code=end
