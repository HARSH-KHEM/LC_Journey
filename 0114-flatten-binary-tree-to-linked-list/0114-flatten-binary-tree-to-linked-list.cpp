/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root){
        if(!root)return NULL ;
        TreeNode* lefttail = solve(root->left);
        TreeNode* righttail = solve(root->right);
        if(lefttail){
            lefttail->right = root->right ;
            root->right = root->left ;
            root->left = NULL ;
        }
        if(righttail)return righttail ;
        if(lefttail)return lefttail ;
        return root ;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};