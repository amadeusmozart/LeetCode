/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
    
        if(lefth > righth)
            return lefth + 1;
        else
            return righth + 1;
    }
    
    void printLevel(TreeNode * root, int level, vector<int>& v)
    {
        if(root == NULL)
            return;
        if(level == 1)
            v.push_back(root->val);
        printLevel(root->left, level - 1, v);
        printLevel(root->right, level - 1, v);
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > vec;
        if(root == NULL)
            return vec;
        int h = maxDepth(root);
        for(int i = h; i >= 1; i--)
        {
            vector<int> v;
            printLevel(root, i, v);
            vec.push_back(v);
        }
    }   
};
