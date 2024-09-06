/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * @brief The implementation of the Solution class, which is used to remove the
 * nth node from the end of a linked list.
 *
 * The solution uses two pointers, fast and slow, to find the nth node from the
 * end of the list. The fast pointer is moved n steps ahead of the slow pointer.
 * Then, both pointers are moved one step at a time until the fast pointer
 * reaches the end of the list. At this point, the slow pointer is pointing to
 * the nth node from the end of the list. The node is then removed by updating
 * the next pointer of the previous node.
 *
 * For example:
 * - Input: 1  ->  2  ->  3  ->  4  ->  5    ,  n = 2
 *         slow          fast
 *                       slow          fast
 *
 * - Output: 1  ->  2  ->  3     4      5
 *                            ↘ ____ ↗
 *                         2nd node from the end
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the number of nodes
 * in the linked list.
 * - The solution has a space complexity of O(1).
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *fast = head, *slow = head;

		while (n--) {
			fast = fast->next;
		}

		// If the fast pointer is null, it means that nth node from the end is
		// the head node
		if (!fast)
			return head->next;

		// Move the fast pointer to the end of the list
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;

		return head;
	}
};
// @lc code=end
