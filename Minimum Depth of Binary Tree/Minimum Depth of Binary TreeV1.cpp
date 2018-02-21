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
    int minD = INT_MAX;
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        findDepth(root,0);
        return minD;
    }
    
    void findDepth(TreeNode *root, int level){
        level++;
        if(!root->left && !root->right){
            minD = min(level,minD);
        }
        if(root->left){
            findDepth(root->left, level);
        }
        if(root->right)
            findDepth(root->right, level);
        return;
    }
    
};