/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * @brief The implementation of the Solution class to return the preorder
 * traversal of an N-ary tree.
 *
 * The Solution class provides a method, preorder, that takes the root of an
 * N-ary tree as input and returns a vector of integers containing the preorder
 * traversal of the tree. The preorder traversal visits the node before its
 * children. The method uses a recursive approach to traverse the tree and store
 * the elements in the preorder sequence in a vector.
 *
 * Algorithm Complexity:
 * - The preorder method has a time complexity of O(n), where n is the number of
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
   private:
	void pre(vector<int>& ans, Node* node) {
		if (!node)
			return;

		ans.push_back(node->val);

		for (auto i : node->children) {
			pre(ans, i);
		}
	}

   public:
	vector<int> preorder(Node* root) {
		vector<int> ans;

		pre(ans, root);

		return ans;
	}
};
// @lc code=end
