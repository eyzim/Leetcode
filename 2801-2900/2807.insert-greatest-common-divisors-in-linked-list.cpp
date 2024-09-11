/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 *
 * @brief The implementation of the Solution class, which is used to insert the
 * greatest common divisors in a linked list.
 *
 * The Solution class provides a method, insertGreatestCommonDivisors, that
 * takes a ListNode pointer, head, as input and inserts the greatest common
 * divisors between the current node and the next node in the linked list. It
 * initializes two ListNode pointers, cur and nextCur, to head and NULL,
 * respectively. It then traverses the linked list and inserts the greatest
 * common divisors between the current node and the next node. The method
 * returns the head of the linked list.
 *
 * Algorithm Complexity:
 * - The insertGreatestCommonDivisors method has a time complexity of O(n),
 * where n is the number of nodes in the linked list.
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
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		ListNode *cur = head, *nextCur;
		// Traverse the linked list and insert the gcd of the current node and
		// the next node between them
		while (cur && cur->next) {
			nextCur = cur->next;
			cur->next = new ListNode(__gcd(cur->val, nextCur->val));
			cur->next->next = nextCur;
			cur = nextCur;
		}

		return head;
	}
};
// @lc code=end
