/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * @brief Given an integer array nums and two integers indexDiff and valueDiff,
 * return true if there are two distinct indices i and j in the array such that
 * abs(nums[i] - nums[j]) <= valueDiff and abs(i - j) <= indexDiff.
 *
 *
 * 1. Solution1: Brute Force
 * The brute force solution is to iterate through all the pairs of indices i and
 * j in the array and check if the conditions abs(nums[i] - nums[j]) <=
 * valueDiff and abs(i - j) <= indexDiff are satisfied. If we find any such pair
 * of indices, we return true. Otherwise, we return false.
 *
 * 2. Solution2: Multiset
 *    abs(nums[i] - nums[j]) <= valueDiff
 * => nums[i] - nums[j] <= valueDiff
 * => nums[i] <= nums[j] + valueDiff
 * => nums[i] - valueDiff <= nums[j]  (1)
 *
 *    abs(i - j) <= indexDiff  (2)
 *
 * From (1) and (2), we can say that if there are two distinct indices i and j
 * in the array such that abs(nums[i] - nums[j]) <= valueDiff and abs(i - j) <=
 * indexDiff, then nums[i] - valueDiff <= nums[j] and i - indexDiff <= j.
 *
 * The idea is to use a multiset to store the elements of the array. We have a
 * window of size indexDiff. We iterate through the array and remove the element
 * which is out of the window in the left side. Then, we find the element which
 * is less than or equal to nums[right] + valueDiff, which is the upper bound of
 * nums[right] - valueDiff (in C++ STL, lower_bound returns the first element
 * that is not less than the given element). If the element is present and the
 * difference is less than or equal to valueDiff, we return true. Otherwise, we
 * insert the current element into the multiset. If we do not find any such pair
 * of indices, we return false.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 *   - The time complexity of the containsNearbyAlmostDuplicate method is
 * O(n^2), where n is the number of elements in the array.
 *  - The space complexity of the method is O(n).
 * 2. Solution2:
 *  - The time complexity of the containsNearbyAlmostDuplicate method is O(n *
 * log(indexDiff)), where n is the number of elements in the array.
 * - The space complexity of the method is O(indexDiff).
 */

// @lc code=start
// O(n^2) solution
class Solution1 {
   public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums,
									   int indexDiff,
									   int valueDiff) {
		vector<pair<long, int>> bucket;

		for (auto i = 0; i < nums.size(); i++) {
			bucket.push_back({nums[i], i});
		}
		sort(bucket.begin(), bucket.end());

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (bucket[j].first - bucket[i].first > valueDiff) {
					break;
				}
				if (abs(bucket[j].second - bucket[i].second) <= indexDiff) {
					return true;
				}
			}
		}

		return false;
	}
};

class Solution2 {
   public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums,
									   int indexDiff,
									   int valueDiff) {
		valueDiff = (long)valueDiff;
		multiset<long> mp;

		for (int right = 0; right < nums.size(); right++) {
			// remove the element which is out of the window in the left side
			if (right > indexDiff) {
				mp.erase((long)nums[right - indexDiff - 1]);
			}

			// find the element which is less than or equal to nums[right] +
			// valueDiff
			// nums[i] - valueDiff <= nums[j]  (1)
			auto it = mp.lower_bound((long)nums[right] - valueDiff);
			if (it == mp.end()) {
				continue;
			}

			// Check if the element is present and the difference is less than
			// or equal to valueDiff
			// abs(i - j) <= indexDiff  (2)
			if (abs(*it - (long)nums[right]) <= valueDiff) {
				return true;
			}

			// insert the current element into the multiset
			mp.insert(nums[right]);
		}

		return false;
	}
};
// @lc code=end
