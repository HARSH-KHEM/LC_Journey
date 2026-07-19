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
    vector<vector<int>>ans ;
    void calc( TreeNode * root  , int t , int sum , vector<int>v){
        if(!root)return ;
        v.push_back(root->val);
        sum += root->val ;
        if(!root->left && !root->right && sum==t){
        ans.push_back(v);
        return ; }
        calc(root->left, t , sum , v);
        calc(root->right , t , sum , v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        calc(root, targetSum , 0 , {});
        return ans ;
    }
};