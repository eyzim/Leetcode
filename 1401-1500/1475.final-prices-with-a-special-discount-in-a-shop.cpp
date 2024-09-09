/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the final prices with a special discount in a shop.
 *
 * The Solution1 class provides a method, finalPrices, that takes a vector of
 * integers, prices, as input and returns a vector of integers representing the
 * final prices after applying the discount. The method iterates through the
 * prices vector and for each price, it iterates through the remaining prices to
 * find the first price that is less than or equal to the current price. If such
 * a price is found, the method subtracts it from the current price and breaks
 * out of the inner loop. Finally, the method returns the updated prices vector.
 * And the Solution2 class provides a method, finalPrices, that takes a vector
 * of integers, prices, as input and returns a vector of integers representing
 * the final prices after applying the discount. The method uses a stack to keep
 * track of the prices that have not been discounted yet. It iterates through
 * the prices vector in reverse order and for each price, it pops the prices
 * from the stack that are greater than the current price and subtracts them
 * from the current price. Finally, the method returns the updated prices
 * vector.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The finalPrices method has a time complexity of O(n^2), where n is the
 * number of prices in the input vector.
 * - The space complexity of the method is O(1).
 * 2. Solution2:
 * - The finalPrices method has a time complexity of O(n), where n is the number
 * of prices in the input vector.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> finalPrices(vector<int>& prices) {
		for (int i = 0; i < prices.size(); i++) {
			for (int j = i + 1; j < prices.size(); j++) {
				if (prices[j] <= prices[i]) {
					prices[i] -= prices[j];
					break;
				}
			}
		}

		return prices;
	}
};

class Solution2 {
   public:
	vector<int> finalPrices(vector<int>& prices) {
		stack<int> st;

		for (int i = prices.size() - 1; i >= 0; i--) {
			while (st.size() && st.top() > prices[i]) {
				st.pop();
			}

			int pri = prices[i];
			if (st.size()) {
				prices[i] -= st.top();
			}

			st.push(pri);
		}

		return prices;
	}
};
// @lc code=end
