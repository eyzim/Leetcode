/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * binary number represented by a linked list to an integer.
 *
 * The Solution class provides a method, getDecimalValue, that takes a linked
 * list as input and returns the decimal value of the binary number represented
 * by the linked list. Once the value of the node is obtained, it is multiplied
 * by 2 and added to the result. The process continues until the end of the list
 * is reached.
 *
 * Algorithm Complexity:
 * - The getDecimalValue method has a time complexity of O(n), where n is the
 * number of nodes in the linked list.
 * - The space complexity of the getDecimalValue method is O(1).
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
	int getDecimalValue(ListNode* head) {
		int ans = 0;

		while (head) {
			ans = ans * 2 + head->val;
			head = head->next;
		}

		return ans;
	}
};
// @lc code=end
