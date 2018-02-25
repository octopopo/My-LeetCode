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
    int maxPath = 0;
    
    
    int longestUnivaluePath(TreeNode* root) {
        int res = findPath(root, INT_MAX);
        
        return maxPath;
    }
    
    int findPath(TreeNode *root, int paVal){
        int lefty = 0, righty = 0;
        if(!root)
            return 0;
        if(root->left)
            lefty = findPath(root->left,root->val);
        if(root->right)
            righty = findPath(root->right, root->val);
        
        int count = 0;
        if(root->left && root->right && root->left->val == root->right->val && root->val == root->left->val){
            int temp = lefty + righty;
            maxPath = max(maxPath, temp);
        }
        count = max(lefty, righty);
        if(root->val == paVal)
            count++;
        else{
            maxPath = max(maxPath, count);
            count = 0;
        }
        
        return count;
        
    }
};