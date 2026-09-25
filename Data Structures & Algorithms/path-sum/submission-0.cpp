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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return hasSumRecurse(root, targetSum, 0);
    }

    bool hasSumRecurse(TreeNode* root, int targetSum, int curSum)
    {
        curSum += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            return (targetSum == curSum);
        }

        if (root->left != nullptr && hasSumRecurse(root->left, targetSum, curSum))
            return true;
        if (root->right != nullptr && hasSumRecurse(root->right, targetSum, curSum))
            return true;
        return false;
    }
};