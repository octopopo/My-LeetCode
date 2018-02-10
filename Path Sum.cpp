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
    bool isHas = false;
    int total_sum;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        total_sum = sum;
        searchNode(root, 0);    
        return isHas;
        
    }
    void searchNode(TreeNode* root, int sum){
        int tempSum = 0;
        tempSum = sum + root->val;
        if(root->left){
            searchNode(root->left,tempSum);
        }
        if(root->right){
            searchNode(root->right, tempSum);
        }
        //to test whether this node is a leaf
        if(!root->right && !root->left){
            isHas = isHas | (tempSum == total_sum);
            return;
        }
        return;
    }
};