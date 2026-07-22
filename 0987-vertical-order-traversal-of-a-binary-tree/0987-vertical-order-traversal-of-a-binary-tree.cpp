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
    map<int,map<int,multiset<int>>>mp ;
    void calc(TreeNode* root , int row , int col){
    if(!root) return ;
    mp[col][row].insert(root->val);
    calc(root->left , row+1 , col-1);
    calc(root->right , row+1 , col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        calc(root,0,0);
        vector<vector<int>>ans ;
       for(auto &col : mp){
        vector<int>temp ;
        for(auto &row : col.second){
            for(auto val : row.second){
                temp.push_back(val);
            }
         }
         ans.push_back(temp);
       }
       return ans ;
    }
};