/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Compare
{
public:
    bool operator () (int i, int j)
    {
        return i > j;
    }
};

class BSTIterator {
public:
    priority_queue<int, std::vector<int>, Compare> pq;
    
    BSTIterator(TreeNode *root) {
        if(root){
            cout << "helo" << endl;
            GoThroughTree(root);
        }
    }
    
    void GoThroughTree(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        GoThroughTree(root->right);
        pq.push(root->val);
        GoThroughTree(root->left);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !pq.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(!pq.empty())
        {
            int tTop = pq.top();
            pq.pop();
            return tTop;
        }
        return 0;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */