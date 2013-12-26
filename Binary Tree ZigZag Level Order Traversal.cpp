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
    
    void printLevel(TreeNode * root, int level, vector<int> & v)
    {
        if(root == NULL)
            return;
        if(level == 1)
            v.push_back(root->val);
        printLevel(root->left, level - 1, v);
        printLevel(root->right, level - 1, v);
        
    }
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int h = maxDepth(root);
        vector<vector<int> > vec;
        
        for(int i = 1; i <= h; i++)
        {   
            vector<int> v;
            if(i % 2 == 1){
                printLevel(root, i, v);
                vec.push_back(v);
            }
            else
            {
                printLevel(root, i, v);
                reverse(v.begin(), v.end());
                vec.push_back(v);
            }
        }
        return vec;
    }
};
