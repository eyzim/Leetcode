/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * @brief The implementation of the Solution class, which is used to sort an
 * array of integers such that the even integers are at even indices and the odd
 * integers are at odd indices. Mind that the input array is guaranteed to have
 * an equal number of even and odd integers in random positions!!!!
 *
 * The Solution class provides a method, sortArrayByParityII, that takes a
 * vector of integers as input and returns a vector of integers containing the
 * elements sorted such that the even integers are at even indices and the odd
 * integers are at odd indices. The method uses two approaches to solve the
 * problem:
 * 1. The first approach uses an additional vector to store the sorted elements.
 * It iterates through the input array and places the even integers at even
 * indices and the odd integers at odd indices in the new vector.
 * 2. The second approach uses a two-pointer approach to iterate through the
 * input array and swap the elements to place the even integers at even indices
 * and the odd integers at odd indices.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The sortArrayByParityII method has a time complexity of O(n), where n is
 * the number of elements in the input array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the input array.
 * 2. Solution2:
 * - The sortArrayByParityII method has a time complexity of O(n), where n is
 * the number of elements in the input array.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		vector<int> ans(nums.size());
		int even = 0, odd = 1;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 == 1) {
				ans[odd] = nums[i];
				odd += 2;
			} else {
				ans[even] = nums[i];
				even += 2;
			}
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		int even = 0, odd = 1;

		while (even < nums.size() && odd < nums.size()) {
			if (nums[even] % 2 == 0) {
				even += 2;
				continue;
			}
			if (nums[odd] % 2 == 1) {
				odd += 2;
				continue;
			}

			swap(nums[odd], nums[even]);
		}

		return nums;
	}
};
// @lc code=end
