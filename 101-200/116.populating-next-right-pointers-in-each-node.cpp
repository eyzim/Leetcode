/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * @brief The next pointer of each node points to its next right node. If there
 * is no next right node, the next pointer should be set to NULL.
 *
 * The Solution class provides a method, connect, that takes a Node pointer,
 * root, as input and returns the root of the binary tree with the next pointers
 * set. It uses a queue to traverse the binary tree level by level and sets the
 * next pointers accordingly. Finally, it returns the root of the binary tree.
 *
 * Algorithm Complexity:
 * - The connect method has a time complexity of O(n), where n is the number of
 * nodes in the binary tree.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
   public:
	Node* connect(Node* root) {
		if (!root)
			return root;

		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			int q_size = q.size();

			for (int i = 0; i < q_size; i++) {
				Node* n = q.front();
				q.pop();

				// If this is the last node in the current level, then set its
				// next pointer to NULL Otherwise, set its next pointer to the
				// front of the queue
				if (i != q_size - 1) {
					n->next = q.front();
				}

				if (n->left) {
					q.push(n->left);
				}
				if (n->right) {
					q.push(n->right);
				}
			}
		}

		return root;
	}
};
// @lc code=end
