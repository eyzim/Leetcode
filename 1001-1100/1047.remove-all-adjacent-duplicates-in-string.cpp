/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * @brief The implementation of the Solution class, which is used to remove all
 * adjacent duplicates in a string.
 *
 * In solution 1, the Solution class provides a method, removeDuplicates, that
 * takes a string, s, as input and removes all adjacent duplicates in the
 * string. It uses a stack to store the characters of the string and removes the
 * top element if it is the same as the current element. Finally, it constructs
 * the result string by popping the elements from the stack. In solution 2, the
 * Solution class provides a method, removeDuplicates, that takes a string, s,
 * as input and removes all adjacent duplicates in the string. It iterates
 * through the string and removes the adjacent duplicates by erasing the
 * characters from the string. It continues the process until no adjacent
 * duplicates are found.
 *
 * Algorithm Complexity:
 * 1. Solution 1:
 * - The removeDuplicates method has a time complexity of O(n), where n is the
 * length of the string.
 * - The space complexity of the method is O(n).
 * 2. Solution 2:
 * - The removeDuplicates method has a time complexity of O(n^2), where n is the
 * length of the string.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	string removeDuplicates(string s) {
		if (s.size() == 1)
			return s;

		stack<char> st;

		// Iterate through the string and remove the adjacent duplicates
		for (auto i : s) {
			if (st.size() && i == st.top()) {
				st.pop();
			} else {
				st.push(i);
			}
		}

		// Construct the result string by popping the elements from the stack
		string ans = "";
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		// Though the stack is LIFO, the elements are popped in reverse order
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

// Note that this solution is as same as question 1700. Number of Students
// Unable to Eat Lunch
class Solution2 {
   public:
	string removeDuplicates(string s) {
		int i = 0;

		while (point < s.size()) {
			if (s[i] == s[i + 1]) {
				s.erase(s.begin() + i, 2);
				i = 0;
			} else {
				i++;
			}
		}

		return s;
	}
};

// @lc code=end
