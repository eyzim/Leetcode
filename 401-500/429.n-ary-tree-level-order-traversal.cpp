/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * @brief The implementation of the Solution class, which is used to perform a
 * level order traversal of an N-ary tree.
 *
 * The Solution class provides a method, levelOrder, that takes a Node pointer,
 * root, as input and returns a vector of vectors of integers representing the
 * level order traversal of the N-ary tree. First, it initializes a vector of
 * vectors of integers, ans, and calls a helper function, bfs, to perform a
 * breadth-first search traversal of the N-ary tree. The bfs function takes a
 * vector of vectors of integers, ans, and a Node pointer, node, as input and
 * performs a breadth-first search traversal of the N-ary tree. It initializes a
 * queue, q, and pushes the root node into the queue. It then iterates over the
 * queue until it is empty, collecting the nodes of each level and adding them
 * to the ans vector. Finally, it returns the ans vector.
 *
 * Algorithm Complexity:
 * - The levelOrder method has a time complexity of O(n), where n is the number
 * of nodes in the N-ary tree.
 * - The space complexity of the method is O(n).
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
	void bfs(vector<vector<int>>& ans, Node* node) {
		if (!node)
			return;

		queue<Node*> q;
		q.push(node);

		while (!q.empty()) {
			int q_size = q.size();
			vector<int> level(q_size);

			for (int i = 0; i < q_size; i++) {
				Node* n = q.front();
				q.pop();

				level[i] = n->val;

				// If any child is present, push it to the queue
				for (auto i : n->children) {
					if (i)
						q.push(i);
				}
			}

			ans.push_back(level);
		}
	}

   public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ans;

		bfs(ans, root);

		return ans;
	}
};
// @lc code=end
