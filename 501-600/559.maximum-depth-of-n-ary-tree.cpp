/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 *
 * @brief The implementation of the Solution class, which is used to find the
 * maximum depth of an N-ary tree.
 *
 * The Solution class provides a method, maxDepth, that takes a Node pointer as
 * input and returns an integer value representing the maximum depth of the
 * N-ary tree. The method uses a recursive approach to traverse the tree and
 * calculate the maximum depth. It initializes a variable, cur, to store the
 * current depth and updates it based on the depth of the children nodes. The
 * method returns 1 plus the maximum depth of the children nodes.
 *
 * Algorithm Complexity:
 * - The maxDepth method has a time complexity of O(n), where n is the number of
 * nodes in the N-ary tree.
 * - The space complexity of the method is O(n), where n is the number of nodes
 * in the N-ary tree.
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
   public:
	int maxDepth(Node* root) {
		if (!root)
			return 0;

		// Initialize the current depth to 0.
		int cur = 0;
		// Traverse the children nodes and update the deepest depth to cur.
		for (auto i : root->children) {
			cur = max(cur, maxDepth(i));
		}

		// Return 1 plus the maximum depth of its children nodes.
		return 1 + cur;
	}
};
// @lc code=end
