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
    unordered_map<int,int>mp ;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder , int preL , int preR , int inL , int inR){
        if(preL > preR || inL>inR)return NULL ;
        TreeNode * root = new TreeNode(preorder[preL]);
        int rootidx = mp[root->val];
        int leftsize = rootidx - inL ;
        root->left = build(preorder,inorder,preL+1,preL+leftsize , inL , rootidx - 1);
        root->right = build(preorder,inorder,preL+leftsize+1,preR , rootidx +1  , inR);
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for( int i = 0 ; i<inorder.size() ; i++){
            mp[inorder[i]]=i ;
        }
        return build(preorder,inorder,0,preorder.size()-1, 0 , inorder.size()-1);
    }
};