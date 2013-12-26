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
    /*
    void pretrav(TreeNode * root, vector<int>& v)
    {
        if(root != NULL)
        {
            v.push_back(root->val);
            pretrav(root->left,v);
            pretrav(root->right,v);
        }
    }
    */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> t;
        stack<TreeNode *> s;
        do{
            while(root != NULL)
            {
                s.push(root);
                t.push_back(root->val);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                root = root->right;
            }
        } while(!s.empty() || root != NULL);
        return t;
    }
};
