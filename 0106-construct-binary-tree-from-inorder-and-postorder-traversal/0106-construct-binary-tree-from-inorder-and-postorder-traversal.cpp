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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int inL , int inR , int postL , int postR){
        if(inL>inR || postL > postR)return NULL ;
        TreeNode * root = new TreeNode(postorder[postR]);
        int rootidx = mp[root->val];
        int ls = rootidx - inL ;
        root->left = build(inorder,postorder,inL,rootidx-1,postL , postL+ls-1);
        root->right = build(inorder,postorder,rootidx+1,inR,postL+ls , postR-1);
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int cnt = 0 ;
        for( auto x : inorder){
            mp[x] = cnt ;
            cnt++ ;
        }
        return build(inorder,postorder,0,inorder.size()-1 , 0 , inorder.size()-1);
    }
};