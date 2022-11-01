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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) return true;
        root->right = invert(root->right);

		return isSame(root->left, root->right);
    }

	TreeNode *invert(TreeNode *root)
	{
		if (root == nullptr) return root;
		std::swap(root->left, root->right);
		root->left = invert(root->left);
		root->right = invert(root->right);

		return root;
	}

	bool isSame(TreeNode *tree1, TreeNode *tree2)
	{
		if (tree1 == nullptr && tree2 == nullptr) return true;
		if (tree1 == nullptr || tree2 == nullptr) return false;

		return tree1->val == tree2->val && isSame(tree1->left, tree2->left) && isSame(tree1->right, tree2->right);
	}
};