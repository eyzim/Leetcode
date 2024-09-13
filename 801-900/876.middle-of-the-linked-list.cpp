/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 *
 * @brief Given a non-empty, singly linked list with head node head, return a
 * middle node of linked list.
 *
 * The solution uses two pointers, slow and fast, to traverse the linked list.
 * The slow pointer moves one step at a time, while the fast pointer moves two
 * steps at a time. When the fast pointer reaches the end of the linked list,
 * the slow pointer will be at the middle of the linked list. The solution
 * returns the slow pointer as the middle node.
 *
 * Algorithm Complexity:
 * - The middleNode method has a time complexity of O(n), where n is the number
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
	ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}
};
// @lc code=end
