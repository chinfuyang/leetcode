#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
		if (!root) return root;

		std::swap(root->left, root->right);
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);

		return root;
    }

    TreeNode *invertTree2(TreeNode *root)
    {
		std::stack<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *cur = q.top();
			q.pop();

			if (!cur) continue;
			q.push(cur->left);
			q.push(cur->right);
			std::swap(cur->left, cur->right);
		}

		return root;
    }
};