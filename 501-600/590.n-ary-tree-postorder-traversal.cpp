/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * @brief The implementation of the Solution class to return the postorder
 * traversal of an N-ary tree.
 *
 * The Solution class provides a method, postorder, that takes the root of an
 * N-ary tree as input and returns a vector of integers containing the postorder
 * traversal of the tree. The postorder traversal visits the children of a node
 * before the node itself. The method uses a recursive approach to traverse the
 * tree and store the elements in the postorder sequence in a vector.
 *
 * Algorithm Complexity:
 * - The postorder method has a time complexity of O(n), where n is the number
 * of nodes in the N-ary tree.
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
   private:
	void post(vector<int>& ans, Node* node) {
		if (!node)
			return;

		for (auto i : node->children) {
			post(ans, i);
		}

		ans.push_back(node->val);
	}

   public:
	vector<int> postorder(Node* root) {
		vector<int> ans;

		post(ans, root);

		return ans;
	}
};
// @lc code=end
