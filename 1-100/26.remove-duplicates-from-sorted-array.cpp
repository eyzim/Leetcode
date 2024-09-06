/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * @brief The implementation of the Solution class, which is used to remove the
 * duplicates from a sorted array.
 *
 * The first implementation of the Solution class provides a method,
 * removeDuplicates, that takes a vector of integers, nums, as input and removes
 * the duplicates from the sorted array. It iterates through the array and
 * removes the duplicates by erasing the elements from the vector. The second
 * implementation of the Solution swaps the elements which are not duplicates to
 * the front of the array.
 *
 * Algorithm Complexity:
 * - The time complexity of the two implementations is O(n), where n is the
 * number of elements in the array.
 * - The space complexity of the two implementations is O(1).
 */

// @lc code=start
class Solution {
   public:
	int removeDuplicates(vector<int>& nums) {
		for (auto i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		return nums.size();
	}
};

class Solution {
   public:
	int removeDuplicates(vector<int>& nums) {
		int j = 1;

		for (auto i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[i - 1]) {
				nums[j] = nums[i];
				j++;
			}
		}

		return j;
	}
};
// @lc code=end
