/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 *
 * @brief The implementation of the Solution class, which is used to find the
 * missing observations in the dice rolls to achieve the target mean.
 *
 * The solution calculates the sum of the dice rolls and the missing
 * observations, by calculating the sum of the target mean and the number of
 * dice rolls and missing observations. It then iterates through the dice rolls
 * and subtracts each roll from the sum. If the sum becomes less than the number
 * of missing observations, it returns an empty vector. If the sum becomes
 * greater than six times the number of missing observations, it returns an
 * empty vector. Otherwise, it calculates the average value of the missing
 * observations and fills the vector with the average value. It then fills the
 * remaining values in the vector with the average value plus one until the sum
 * is reached.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n), where n is the number of dice
 * rolls.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int sum = mean * (rolls.size() + n);

		for (auto i : rolls) {
			sum -= i;
			if (sum < n) {
				return {};
			}
		}

		if (sum > 6 * n)
			return {};

		vector<int> ans(n, sum / n);
		sum -= n * ans[0];

		for (auto i = 0; i < sum; i++) {
			ans[i]++;
		}

		return ans;
	}
};
// @lc code=end
