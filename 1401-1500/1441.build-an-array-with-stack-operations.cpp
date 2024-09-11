/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 *
 * @brief The implementation of the Solution class, which is used to build an
 * array with stack operations.
 *
 * The Solution class provides a method, buildArray, that takes a vector of
 * integers, target, and an integer, n, as input and returns a vector of
 * strings. The method initializes a vector of strings, ans, and an integer, t,
 * to 0. It then iterates from 1 to n and checks if the target array is already
 * generated. If the elements in the target array are found, the method pushes
 * the element to the ans vector. If the elements are not in the target array,
 * the method pushes and pops the element. Finally, the method returns the ans
 * vector.
 *
 * Algorithm Complexity:
 * - The buildArray method has a time complexity of O(n), where n is the number
 * of elements in the target array.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ans;

		int t = 0;
		for (auto i = 1; i <= n; i++) {
			// the target array is already generated
			if (t == target.size())
				break;

			// if the elements in the target, we only need to push
			if (target[t] == i) {
				ans.push_back("Push");
				t++;
			}
			// if the elements are not in the target, we need to push and pop
			else {
				ans.push_back("Push");
				ans.push_back("Pop");
			}
		}

		return ans;
	}
};
// @lc code=end
