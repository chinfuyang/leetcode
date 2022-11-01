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

		return isSymmetricTree(root->left, root->right);
    }

	bool isSymmetricTree(TreeNode *left, TreeNode *right)
	{
		if (left == nullptr && right == nullptr) return true;
		if (left == nullptr || right == nullptr) return false;

		return left->val == right->val && isSymmetricTree(left->right, right->left) && isSymmetricTree(left->left, right->right);
	}
};