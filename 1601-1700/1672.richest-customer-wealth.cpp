/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum wealth of a customer.
 *
 * The Solution class provides a method, maximumWealth, that takes a vector of
 * vectors of integers as input and returns the maximum wealth of a customer.
 * The method iterates through the vector of vectors and calculates the wealth
 * of each customer by summing the wealth in each account. The maximum wealth is
 * then updated if the current customer's wealth is greater than the maximum
 * wealth.
 *
 * Algorithm Complexity:
 * - The maximumWealth method has a time complexity of O(n*m), where n is the
 * number of customers and m is the number of accounts.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int maxi = 0;
		for (auto i : accounts) {
			int myWealth = 0;
			for (auto j : i) {
				myWealth += j;
			}
			maxi = max(maxi, myWealth);
		}

		return maxi;
	}
};
// @lc code=end
