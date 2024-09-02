/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * @brief The implementation of the Solution class, which is used to find the
 * top k frequent words in a list of words. Note that the words must be printed
 * in the order of decreasing frequency, and if two words have the same
 * frequency, the word with the lexicographically smaller order should come
 * first.
 *
 * The Solution class provides a method, topKFrequent, that takes a vector of
 * strings and an integer k as input and returns a vector of strings
 * representing the top k frequent words in the list. The method uses a map to
 * store the frequency of each word in the list. It then creates a min heap to
 * store the top k frequent words. The method iterates over the map and pushes
 * the words into the min heap. If the size of the min heap exceeds k, it pops
 * the top element. Finally, the method creates a vector to store the top k
 * frequent words and returns it.
 *
 * Algorithm Complexity:
 * - The topKFrequent method has a time complexity of O(n*log(k)), where n is
 * the number of words in the list.
 * - The space complexity of the method is O(n), where n is the number of words
 * in the list.
 */

// @lc code=start
class Solution {
   public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		if (words.size() < k)
			return words;

		// Create a map to store the frequency of each word.
		unordered_map<string, int> mp;
		for (auto i : words) {
			mp[i]++;
		}

		// Create a min heap to store the top k frequent words.
		priority_queue<pair<int, string>, vector<pair<int, string>>> pq;
		for (auto i : mp) {
			// Trick: use negative frequency to make the min heap a max heap
			pq.push(make_pair(-i.second, i.first));
			if (pq.size() > k)
				pq.pop();
		}

		// Create a vector to store the top k frequent words.
		vector<string> ans(k);
		for (auto i = k - 1; i >= 0; i--) {
			ans[i] = pq.top().second;
			pq.pop();
		}
		return ans;
	}
};
// @lc code=end
