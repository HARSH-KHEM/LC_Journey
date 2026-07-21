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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,int preL , int preR , int postL , int postR){
        if(preL>preR)return NULL ;
        TreeNode* root = new TreeNode(preorder[preL]);
        if(preL == preR) return root ;
        int leftroot = preorder[preL+1] ;
        int subrootidx = mp[leftroot];
        int ls = subrootidx - postL +1 ;
        root->left = build(preorder,postorder,preL+1,preL+ls,postL,subrootidx);
        root->right = build(preorder,postorder,preL+ls + 1,preR,subrootidx+1 ,postR-1);
        return root ;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int cnt = 0 ;
        for(auto x : postorder){
            mp[x]=cnt ;
            cnt++;
        }
        return build(preorder,postorder,0,postorder.size()-1,0,postorder.size()-1);
    }
};