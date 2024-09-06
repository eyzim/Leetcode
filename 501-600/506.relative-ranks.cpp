/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * @brief The implementation of the Solution class, which is used to find the
 * ranks of the athletes based on their scores.
 *
 * The solution uses a priority queue to store the scores and their indices from
 * the highest score to the lowest. It then defines the medals and creates a
 * vector to store the ranks. Finally, it iterates through the priority queue
 * and assigns the ranks to the athletes based on their scores.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n log n), where n is the size of
 * the scores vector.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<string> findRelativeRanks(vector<int>& score) {
		// Create a priority queue to store the scores and their indices from
		// the highest score to the lowest.
		priority_queue<pair<int, int>> pq;
		for (auto i = 0; i < score.size(); i++) {
			pq.push({score[i], i});
		}

		// Define the medals.
		vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

		// Create a vector to store the ranks.
		vector<string> ans(score.size());
		int count = 0;
		while (!pq.empty()) {
			int pos = pq.top().second;
			if (count < 3) {
				ans[pos] = medals[count];
			} else {
				ans[pos] = to_string(count + 1);
			}
			count++;
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
