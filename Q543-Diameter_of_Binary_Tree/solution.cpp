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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        depth(root);
        return _max;
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        _max = std::max(_max, left + right);


        return max(left, right) + 1;
    }
private:
    int _max = 0;
};