/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * @brief The implementation of the Solution class, which is used to merge two
 * sorted linked lists.
 *
 * The solution compares the values of the two lists and merges them in
 * ascending order. It reconnects the nodes of the two lists to form a new list.
 * It then concatenates the remaining list to the new list.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n + m), where n and m are the sizes
 * of the two lists.
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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// Store the head of the new list
		ListNode* ans = new ListNode();
		ListNode* cur = ans;

		// Compare the values of the two lists and make the cur point to the
		// smaller value
		while (list1 && list2) {
			if (list1->val < list2->val) {
				cur->next = list1;
				list1 = list1->next;
			} else {
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}

		// Concatenate the remaining list
		if (list1)
			cur->next = list1;
		else if (list2)
			cur->next = list2;

		return ans->next;
	}
};
// @lc code=end
