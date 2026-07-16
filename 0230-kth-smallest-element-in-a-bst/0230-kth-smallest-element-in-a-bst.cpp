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
    int cnt = 0 ;
    int ans = 0 ;
    int k ;
    void solve(TreeNode* root){
        if(root==NULL || cnt>=k)return ;
        solve(root->left);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int K) {
        k=K;
        solve(root);
        return ans ;
    }
};