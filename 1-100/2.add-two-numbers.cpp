/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * @brief The implementation of the Solution class, which is used to add two
 * numbers represented by linked lists.
 *
 * The solution uses a while loop to iterate through the linked lists and
 * calculate the sum of the corresponding nodes. It then creates a new linked
 * list to store the result. It uses a pointer to traverse the linked list and
 * add the sum of the nodes. It also handles the carry-over values while adding
 * the nodes.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the size of the
 * linked list.
 * - The solution has a space complexity of O(n).
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// Create a pointer to the answer list
		ListNode* ans = new ListNode();
		// Create a pointer to the answer list and goint to use it to traverse
		// the list
		ListNode* p = ans;

		int sum = 0;
		while (l1 || l2 || sum) {
			if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}

			// if sum is greater than 10 then we need to carry over the value
			p->next = new ListNode(sum % 10);
			sum /= 10;
			// move the pointer to the next node
			p = p->next;
		}

		return ans->next;
	}
};
// @lc code=end
