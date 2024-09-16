/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 *
 * @brief Given a list of 24-hour clock time points in "HH:MM" format, return
 * the minimum minutes difference between any two time-points in the list.
 *
 * The idea is to convert the time points to minutes and store them in a
 * multiset. Then, we can find the minimum difference between any two time
 * points. We need to insert the time points twice in the multiset to handle the
 * case where the minimum difference is between the first and the last time
 * points. For example, the minimum difference between "00:00" and "23:59" is 1
 * minute. If we insert the time points only once, the difference will be 1439
 * minutes.
 *
 * Algorithm Complexity:
 * - Time complexity: O(nlogn)
 * - Space complexity: O(n)
 */

// @lc code=start
class Solution {
   public:
	int findMinDifference(vector<string>& timePoints) {
		multiset<int> mp;

		// Convert the time points to minutes and store them in a multiset.
		for (auto i : timePoints) {
			int hour = (time[0] - '0') * 10 + (time[1] - '0');
			int minute = (time[3] - '0') * 10 + (time[4] - '0');
			int totalMinutes = hour * 60 + minute;

			mp.insert(totalMinutes);
			// Insert the time points twice to handle the case where the minimum
			// difference is between the first and the last time points.
			mp.insert(totalMinutes + 1440);
		}

		// Find the minimum difference between any two time points.
		int diff = INT_MAX;
		int previousTime = -1440;  // Initialize to a value that ensures the
								   // first comparison is valid

		for (auto& i : mp) {
			diff = min(diff, i - previousTime);
			previousTime = i;
		}

		return diff;
	}
};
// @lc code=end
