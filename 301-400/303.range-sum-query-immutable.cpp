/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * @brief The implementation of the NumArray class, which is used to calculate
 * the sum of a range of elements in an array.
 *
 * The NumArray class provides a constructor that takes a vector of integers as
 * input and calculates the prefix sum of the input array. The class also
 * provides a method, sumRange, that takes two integers, left and right, as
 * input and returns the sum of the elements in the input array from index left
 * to index right. The sumRange method uses the prefix sum to calculate the sum
 * of the elements in the given range.
 *
 * Algorithm Complexity:
 * - The NumArray constructor has a time complexity of O(n), where n is the
 * number of elements in the input array.
 * - The sumRange method has a time complexity of O(1).
 * - The space complexity of the NumArray class is O(n), where n is the number
 * of elements in the input array.
 */

// @lc code=start
class NumArray {
   private:
	vector<int> prefix;

   public:
	NumArray(vector<int>& nums) {
		int sum = 0;

		// Reserve memory for the prefix sum vector
		prefix.reserve(nums.size());

		// Calculate the prefix sum
		for (auto i : nums) {
			sum += i;
			prefix.push_back(sum);
		}
	}

	int sumRange(int left, int right) {
		// If left is 0, return the prefix sum at index right; otherwise, return
		// the difference between the prefix sum at index right and the prefix
		// sum at index left - 1
		return left == 0 ? prefix[right] : prefix[right] - prefix[left - 1];
	}
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
