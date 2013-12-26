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
    vector<int> inorderTraversal(TreeNode *root) {
       vector<int> v;
       if(root == NULL)
           return v;
       stack<TreeNode *> s;
       do{
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            if(!s.empty())
            {
                root = s.top();
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
       } while(!s.empty() || root != NULL);
    }
};
