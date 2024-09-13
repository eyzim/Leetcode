/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * @brief The implementation of the Solution class, which is used to swap nodes
 * in pairs.
 *
 * The Solution class provides a method, swapPairs, that takes a ListNode
 * pointer, head, as input and swaps the nodes in pairs. It initializes three
 * ListNode pointers, prev, cur, and p, to a new ListNode, prev, and sets
 * prev->next to head. It then iterates through the linked list, swapping the
 * nodes in pairs. Finally, it returns the head of the linked list.
 * For example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 1. Initialize prev, cur, and p to a new ListNode, prev, and set prev->next to
 * head.
 * 2. While cur->next and cur->next->next are not NULL:
 *  a. Set p to cur->next->next.
 *  b. Swap the nodes cur->next->next and cur->next.
 *  c. Swap the nodes cur->next and p.
 *  d. Set cur to p->next.
 *
 * Algorithm Complexity:
 * - The swapPairs method has a time complexity of O(n), where n is the number
 * of nodes in the linked list.
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
	ListNode* swapPairs(ListNode* head) {
		ListNode *prev = new ListNode(), *cur = prev, *p;
		prev->next = head;

		while (cur->next && cur->next->next) {
			p = cur->next->next;
			cur->next->next = p->next;
			p->next = cur->next;
			cur->next = p;
			cur = p->next;
		}

		return prev->next;
	}
};
// @lc code=end
