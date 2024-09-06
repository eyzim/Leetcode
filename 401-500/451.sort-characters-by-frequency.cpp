/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * @brief The implementation of the Solution class, which is used to sort the
 * characters in a string by their frequency.
 *
 * The solution uses a map to store the frequency of each character in the
 * string. It then creates a priority queue to store the characters in
 * descending order of frequency. Finally, it constructs the result string by
 * appending the characters from the priority queue.
 *
 * Algorithm Complexity:
 * - The solution has a time complexity of O(n log n), where n is the size of
 * the string.
 * - The solution has a space complexity of O(n).
 */

// @lc code=start
class Solution {
   public:
	string frequencySort(string s) {
		// Create a map to store the frequency of each character
		unordered_map<char, int> mp;
		for (auto i : s) {
			mp[i]++;
		}

		// Create a priority queue to store the characters in descending order
		// of frequency
		priority_queue<pair<int, char>> pq;
		for (auto i : mp) {
			pq.push({i.second, i.first});
		}

		// Create a string to store the result
		string ans = "";
		while (!pq.empty()) {
			ans.append(pq.top().first, pq.top().second);
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
