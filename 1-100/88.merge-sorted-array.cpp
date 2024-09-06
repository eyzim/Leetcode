/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * @brief The implementation of the Solution class, which is used to merge two
 * sorted arrays.
 *
 * The first solution is a simple solution that merges the two arrays and sorts
 * the result. The second solution is a more efficient solution that merges the
 * two arrays in place, starting from the end of the two arrays and moving the
 * larger elements to the end of the array.
 *
 * Algorithm Complexity:
 * - The first solution has a time complexity of O((m+n)log(m+n)), where m is
 * the size of the first array and n is the size of the second array.
 * - The second solution has a time complexity of O(m+n).
 * - Both space complexity is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++) {
			nums1[m + i] = nums2[i];
		}

		sort(nums1.begin(), nums1.end());
	}
};
class Solution2 {
   public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = nums1.size() - 1;
		m--;
		n--;

		// Get the larger element from the end of the two arrays and move it to
		// the end of the first array.
		while (m >= 0 && n >= 0) {
			if (nums2[n] >= nums1[m]) {
				nums1[pos] = nums2[n];
				n--;
			} else {
				nums1[pos] = nums1[m];
				m--;
			}
			pos--;
		}

		// Move the remaining elements from the second array to the first array.
		while (n >= 0) {
			nums1[pos--] = nums2[n--];
		}
	}
};
// @lc code=end
