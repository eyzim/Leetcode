/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * @brief The implementation of the Solution class, which is used to find the
 * lexicographically sorted numbers from 1 to n.
 * Note that the question 179.largest-number.cpp is similar to this one.
 *
 * The Solution class provides a method, lexicalOrder, that takes an integer, n,
 * as input and returns a vector of integers that contains the lexicographically
 * sorted numbers from 1 to n. The method first creates a vector of integers,
 * ans, and populates it with numbers from 1 to n. It then sorts the vector
 * using a custom comparator function, comp, which compares the string
 * representations of the numbers. Finally, it returns the sorted vector.
 *
 * Algorithm Complexity:
 * - The lexicalOrder method has a time complexity of O(nlogn), where n is the
 * input integer.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
bool comp(int a, int b) {
	return to_string(a) < to_string(b);
}

class Solution {
   public:
	vector<int> lexicalOrder(int n) {
		vector<int> ans;

		for (auto i = 1; i <= n; i++) {
			ans.push_back(i);
		}

		// Sort the array using the custom comparator function
		sort(ans.begin(), ans.end(), comp);

		return ans;
	}
};
// @lc code=end
