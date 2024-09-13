/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * @brief Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to:
 * L0→Ln→L1→Ln-1→L2→Ln-2→… You may not modify the values in the list's nodes,
 * only nodes itself may be changed.
 *
 * The idea is to first find the middle of the linked list. Then, we can reverse
 * the right half of the linked list. Finally, we can insert the right half of
 * the linked list into the left half of the linked list.
 * Note that finding the middle of the linked list is the same as question 234 &
 * 876.
 * Note that reversing the linked list is the same as question 206.
 *
 * Algorithm Complexity:
 * Time complexity: O(n)
 * Space complexity: O(1)
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
   private:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* prev = NULL;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

   public:
	void reorderList(ListNode* head) {
		if (!head)
			return;

		// Find the middle of the list
		ListNode *slow = head, *fast = head, *prev, *cutHalf;

		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		// Cut the list into two halves
		// If the list has odd number of elements, the left half will have one
		// more element than the right half.
		if (fast) {
			prev = slow;
			slow = slow->next;
		}
		cutHalf = slow;
		prev->next = nullptr;

		// reverse the right half of the list
		cutHalf = reverseList(cutHalf);

		// insert the right half of the list
		slow = head;
		while (slow && cutHalf) {
			ListNode* next = slow->next;
			slow->next = cutHalf;
			cutHalf = cutHalf->next;
			slow->next->next = next;
			slow = next;
		}
	}
};
// @lc code=end
