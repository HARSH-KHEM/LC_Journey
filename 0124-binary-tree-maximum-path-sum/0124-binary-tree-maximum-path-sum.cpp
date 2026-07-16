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
    int sum = INT_MIN ;
     int solve(TreeNode* root){
        if(!root)return 0 ;
        int lh = max(0,solve(root->left));
        int rh = max(0,solve(root->right));
        sum=max(sum,root->val +lh+rh);
        return max(lh,rh)+ root->val ;
     }
    int maxPathSum(TreeNode* root) {
        int n = solve(root);
        return sum ;
    }
};