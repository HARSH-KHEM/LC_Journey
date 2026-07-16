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
    int dia = 0 ;
    int mh(TreeNode* root){
        if(!root)return 0;
        int lh = mh(root->left);
        int rh = mh(root->right);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int n = mh(root);
        return dia ;
    }
};