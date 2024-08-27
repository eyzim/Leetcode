/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * @brief The implementation of the Solution class, which is used to convert a
 * sorted array into a height-balanced binary search tree.
 *
 * Given an integer array nums where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree. A height-balanced binary
 * tree is a binary tree in which the depth of the two subtrees of every node
 * never differs by more than one.
 * The Solution class provides a method, sortedArrayToBST, that takes a vector
 * of integers nums as input and returns the root node of the height-balanced
 * binary search tree. The method uses a recursive approach to construct the
 * binary search tree by selecting the middle element of the array as the root
 * node and recursively constructing the left and right subtrees. The final root
 * node of the binary search tree is then returned.
 *
 * Algorithm Complexity:
 * - The sortedArrayToBST method has a time complexity of O(n), where n is the
 * number of elements in the input array.
 * - The space complexity of the method is O(n), where n is the number of
 * elements in the input array.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   private:
	TreeNode* createTree(vector<int>& nums, int start, int end) {
		// Base case: if the start index is greater than the end index, return
		// NULL.
		if (start > end)
			return NULL;

		// The middle element of the array is chosen as the root node.
		int mid = start + (end - start) / 2;
		TreeNode* node = new TreeNode(nums[mid]);

		// Recursively construct the left subtree and make it the left child of
		// the root node.
		node->left = createTree(nums, start, mid - 1);
		node->right = createTree(nums, mid + 1, end);

		return node;
	}

   public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (!nums.size())
			return NULL;

		return createTree(nums, 0, nums.size() - 1);
	}
};
// @lc code=end
