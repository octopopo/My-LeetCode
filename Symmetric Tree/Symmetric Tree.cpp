class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //careful for the null case
        if(!root)
            return true;
        return checkSymmetric(root->left, root->right);
    }
    
    bool checkSymmetric(TreeNode *node1, TreeNode *node2){
        
        if(!node1 && !node2){
            return true;
        }
        else if(!node1 || !node2)
            return false;
        else{
            if(node1->val != node2->val)
                return false;
            else{
                return checkSymmetric(node1->left, node2->right) && checkSymmetric(node1->right, node2->left);
            }
        }
        return true;
    }
};