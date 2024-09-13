/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 *
 * @brief The implementation of the Solution class, which is used to perform XOR
 * queries on a subarray.
 *
 * 1. Solution1:
 * The Solution1 class provides a method, xorQueries, that takes a vector of
 * integers, arr, and a vector of vectors of integers, queries, as input and
 * returns a vector of integers. The method initializes a vector of integers,
 * ans, to store the results of the XOR queries. It then iterates through the
 * queries and calculates the XOR of the subarray using a nested loop. The outer
 * loop iterates through the queries, and the inner loop iterates through the
 * subarray. The method returns the ans vector. But this solution is not
 * efficient as it has a time complexity of O(n^2), where n is the size of the
 * arr vector.
 *
 * 2. Solution2:
 * The Solution2 class provides a method, xorQueries, that takes a vector of
 * integers, arr, and a vector of vectors of integers, queries, as input and
 * returns a vector of integers. The method initializes a vector of integers,
 * prefix, to store the XOR of the subarray. It then calculates the prefix XOR
 * of the arr vector. The method then iterates through the queries and
 * calculates the XOR of the subarray using the prefix vector. The method
 * returns the ans vector. This solution is more efficient as it has a time
 * complexity of O(n), where n is the size of the arr vector.
 *
 * Algorithm Complexity:
 * 1.Solution1:
 * - The xorQueries method has a time complexity of O(n^2), where n is the size
 * of the arr vector.
 * - The space complexity of the method is O(n).
 * 2.Solution2:
 * - The xorQueries method has a time complexity of O(n), where n is the size of
 * the arr vector.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution1 {
   public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> ans(queries.size());

		for (int i = 0; i < queries.size(); i++) {
			int q = 0;
			// Queries from start to end
			for (int j = queries[i][0]; j <= queries[i][1]; j++) {
				q ^= arr[j];
			}
			ans[i] = q;
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		// Calculate the prefix XOR of the arr vector
		// prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
		// ex:
		// prefix[0] = arr[0],
		// prefix[1] = arr[0] ^ arr[1],
		// prefix[2] = arr[0] ^ arr[1] ^ arr[2]
		vector<int> prefix = arr;
		for (auto i = 1; i < prefix.size(); i++) {
			prefix[i] ^= prefix[i - 1];
		}

		vector<int> ans(queries.size());
		for (auto i = 0; i < ans.size(); i++) {
			int start = queries[i][0], end = queries[i][1];

			// If start is 0, then the XOR of the subarray is the prefix[end]
			if (start == 0) {
				ans[i] = prefix[end];
			}
			// Otherwise, the XOR of the subarray is prefix[end] ^ prefix[start
			// - 1]
			// ex:
			// queries[i] = [1, 3]
			// prefix[3] = arr[0] ^ arr[1] ^ arr[2] ^ arr[3]
			// prefix[0] = arr[0]
			// xor from 1 to 3 = prefix[3] ^ prefix[0]
			//                 = (arr[0] ^ arr[1] ^ arr[2] ^ arr[3]) ^ (arr[0])
			else {
				ans[i] = prefix[end] ^ prefix[start - 1];
			}
		}

		return ans;
	}
};
// @lc code=end
