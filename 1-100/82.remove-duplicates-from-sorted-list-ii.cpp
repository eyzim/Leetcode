/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * @brief The implementation of the Solution class, which is used to remove all
 * duplicates from a sorted linked list.
 *
 * The Solution class provides a method, deleteDuplicates, that takes a ListNode
 * pointer, head, as input and removes all duplicates from the sorted linked
 * list. It initializes a ListNode pointer, prev, to a new ListNode with a value
 * of -1 and a next pointer to the head. It then iterates through the linked
 * list, removing all duplicates by updating the next pointer of the previous
 * node. Finally, it returns the next pointer of the dummy node. In solution 2,
 * we can remove all the duplicated nodes at once.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The deleteDuplicates method has a time complexity of O(n), where n is the
 * number of nodes in the linked list.
 * - The space complexity of the method is O(n).
 * 2. Solution2:
 * - The deleteDuplicates method has a time complexity of O(n), where n is the
 * number of nodes in the linked list.
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
class Solution1 {
   public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur = head;
		unordered_map<int, int> mp;
		while (cur) {
			mp[cur->val]++;
			cur = cur->next;
		}

		// Create a dummy node to handle the case where the head is removed.
		ListNode* prev = new ListNode(-1);
		prev->next = head;
		cur = prev;
		while (cur && cur->next) {
			// If the value of the next node is duplicated, remove it.
			if (mp[cur->next->val] > 1) {
				cur->next = cur->next->next;
			} else {
				cur = cur->next;
			}
		}

		return prev->next;
	}
};

class Solution2 {
   public:
	ListNode* deleteDuplicates(ListNode* head) {
		// Create a dummy node to handle the case where the head is removed.
		ListNode* prev = new ListNode(-1);
		prev->next = head;
		ListNode* cur = prev;

		while (cur && cur->next) {
			// If the next node is duplicated, remove it.
			if (cur->next->next && cur->next->val == cur->next->next->val) {
				// Remove all the duplicated nodes.
				while (cur->next->next &&
					   cur->next->val == cur->next->next->val) {
					cur->next = cur->next->next;
				}
				// Remove the last duplicated node.
				cur->next = cur->next->next;
			} else {
				cur = cur->next;
			}
		}

		return prev->next;
	}
};
// @lc code=end
