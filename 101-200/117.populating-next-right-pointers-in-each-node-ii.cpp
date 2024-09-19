/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * @brief This problem is similar to 116, but the tree is not perfect binary
 * tree.
 *
 * The solution is to use BFS or DFS to traverse the tree.
 * For BFS, we can use a queue to store the nodes in the same level.
 * For DFS, we can use a dummy node to store the next level's head node. First,
 * we set the dummy node to the next level's head node. Then we traverse the
 * current level, and set the next pointer to the next node in the same level.
 * If the node has left child, we set the left child to the next node. If the
 * node has right child, we set the right child to the next node. Finally, we
 * set the current node to the next node.
 *
 * Algorithm Complexity:
 * 1. BFS:
 * - Time: O(n)
 * - Space: O(n)
 * 2. DFS:
 * - Time: O(n)
 * - Space: O(1)
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

// BFS
class Solution1 {
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

				if (i == q_size - 1) {
					n->next = NULL;
				} else {
					n->next = q.front();
				}

				if (n->left)
					q.push(n->left);
				if (n->right)
					q.push(n->right);
			}
		}

		return root;
	}
};

// DFS
class Solution {
   public:
	Node* connect(Node* root) {
		if (!root)
			return root;

		// current node to traverse the tree
		Node* cur = root;
		while (cur) {
			// dummy node to store the next level's head node
			Node* dummy = new Node(0);
			// pre node to store the next node in the same level
			Node* pre = dummy;

			while (cur) {
				if (cur->left) {
					pre->next = cur->left;
					pre = pre->next;
				}
				if (cur->right) {
					pre->next = cur->right;
					pre = pre->next;
				}
				cur = cur->next;
			}

			cur = dummy->next;
		}

		return root;
	}
};
// @lc code=end
