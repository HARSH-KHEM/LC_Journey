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
    unordered_map<long long , int>mp ;
    int ans = 0 ;
    void calc(TreeNode * root , long long curr , int t){
        if(!root)return ;
        curr+=root->val ;
        ans+=mp[curr - t];
        mp[curr]++;
        calc(root->left,curr,t);
        calc(root->right,curr,t);
        mp[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        calc(root,0,targetSum );
        return ans ;
    }
};