/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 *
 * @brief The implementation of the Solution class, which is used to decode an
 * XORed array.
 *
 * The Solution class provides a method, decode, that takes an encoded array and
 * the first element of the original array as input and returns the original
 * array.
 *
 * Algorithm Complexity:
 * - The decode method has a time complexity of O(n), where n is the length of
 * the input encoded array.
 * - The space complexity of the decode method is O(n).
 */

// @lc code=start
class Solution {
   public:
	vector<int> decode(vector<int>& encoded, int first) {
		// The first element of the original array is given
		vector<int> ans = {first};

		// XOR the encoded array with the ans array
		for (auto i = 0; i < encoded.size(); i++) {
			unsigned int temp = encoded[i] ^ ans[i];
			ans.push_back(temp);
		}

		return ans;
	}
};
// @lc code=end
