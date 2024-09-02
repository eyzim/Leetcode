/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * @brief The implementation of the Solution class, which is used to find the
 * top k frequent elements in an array.
 *
 * The Solution class provides a method, topKFrequent, that takes a vector of
 * integers and an integer k as input and returns a vector of integers
 * representing the top k frequent elements in the array. The method uses a map
 * to store the frequency of each element in the array. It then creates a min
 * heap to store the top k frequent elements. The method iterates over the map
 * and pushes the elements into the min heap. If the size of the min heap
 * exceeds k, it pops the top element. Finally, the method creates a vector to
 * store the top k frequent elements and returns it.
 *
 * Algorithm Complexity:
 * - The topKFrequent method has a time complexity of O(n*log(k)), where n is
 * the number of elements in the array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the array.
 */

// @lc code=start
class Solution {
   public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// Create a map to store the frequency of each element.
		// time complexity: O(n)
		// space complexity: O(n)
		unordered_map<int, int> mp;
		for (auto i : nums) {
			mp[i]++;
		}

		// Create a min heap to store the top k frequent elements.
		// time complexity: O(n*log(k))
		// space complexity: O(k)
		priority_queue<pair<int, int>, vector<pair<int, int>>,
					   greater<pair<int, int>>>
			pq;
		for (auto i : mp) {
			pq.push(make_pair(i.second, i.first));
			if (pq.size() > k)
				pq.pop();
		}

		// Create a vector to store the top k frequent elements.
		// time complexity: O(k)
		// space complexity: O(k)
		vector<int> ans(k);
		for (auto i = 0; i < k; i++) {
			ans[i] = pq.top().second;
			pq.pop();
		}

		return ans;
	}
};
// @lc code=end
