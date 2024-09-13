/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the final value of a variable after performing operations.
 *
 * Solution1 uses a hash map to store the values of the operations and then sums
 * them up. Solution2 directly sums up the values of the operations. We can find
 * that the second character of the string is '+' or '-'. Then we can directly
 * sum up the values of the operations.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The finalValueAfterOperations method has a time complexity of O(n), where n
 * is the number of operations.
 * - The space complexity of the method is O(1).
 * 2. Solution2:
 * - The finalValueAfterOperations method has a time complexity of O(n), where n
 * is the number of operations.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	int finalValueAfterOperations(vector<string>& operations) {
		unordered_map<string, int> mp;
		mp["++X"] = 1;
		mp["X++"] = 1;
		mp["--X"] = -1;
		mp["X--"] = -1;

		int ans = 0;
		for (auto i : operations) {
			ans += mp[i];
		}

		return ans;
	}
};

class Solution2 {
   public:
	int finalValueAfterOperations(vector<string>& operations) {
		int ans = 0;
		for (auto i : operations) {
			ans += i[1] == '+' ? 1 : -1;
		}

		return ans;
	}
};
// @lc code=end
