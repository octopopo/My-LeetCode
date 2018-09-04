/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
        {
            return nullptr;
        }
        
        if(root == p || root == q)
        {
            return root;
        }
        
        TreeNode *lefty = lowestCommonAncestor(root->left, p, q);
        TreeNode *righty = lowestCommonAncestor(root->right, p, q);
        
        if(lefty && righty)
        {
            return root;
        }
        else
        {
            return lefty ? lefty : righty;
        }
        
    }
};