class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        //if the node don't have any children, it's leaf
        if(!root->right && !root->left && root->val == sum)
            return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};