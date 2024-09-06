/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * @brief Check if a linked list is a palindrome.
 *
 * The idea is to use a stack to store the first half of the linked list. Then,
 * we can compare the second half of the linked list with the elements popped
 * from the stack.
 *
 * Algorithm Complexity:
 * Time complexity: O(n)
 * Space complexity: O(n)
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
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;

		// Use a stack to store the first half of the linked list.
		stack<int> st;
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			st.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}

		// If the linked list has odd number of elements, skip the middle
		// element.
		if (fast) {
			slow = slow->next;
		}

		// Compare the second half of the linked list with the elements popped
		while (!st.empty()) {
			if (slow->val != st.top())
				return false;
			slow = slow->next;
			st.pop();
		}

		// If the linked list is a palindrome, the slow pointer should be NULL.
		return slow == nullptr;
	}
};
// @lc code=end
