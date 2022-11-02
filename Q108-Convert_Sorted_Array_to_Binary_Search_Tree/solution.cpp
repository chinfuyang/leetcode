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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }
    TreeNode *toBST(std::vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        
        TreeNode *midNode = new TreeNode(nums[mid]);

        midNode->left = toBST(nums, left, mid - 1);
        midNode->right = toBST(nums, mid + 1, right);

        return midNode;
    }
};