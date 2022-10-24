#include <vector>
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
class Solution {
public:
    bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int maxLefttHeight = maxHeight(root->left);
		int maxRighttHeight = maxHeight(root->right);

		return abs(maxLefttHeight - maxRighttHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

	int maxHeight(TreeNode *root) {
		if (!root) return 0;

		int maxLefttHeight = maxHeight(root->left);
		int maxRighttHeight = maxHeight(root->right);

		return max(maxLefttHeight, maxRighttHeight) + 1;
	}
};