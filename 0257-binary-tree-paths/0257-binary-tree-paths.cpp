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
    vector<string>ans ;
    void calc(TreeNode * root , string path){
        if(!root)return ;
        if(path.empty())path += to_string(root->val);
        else path += "->" + to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(path);
            return; 
            }
        calc(root->left , path);
        calc(root->right , path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        calc(root,"");
        return ans ;
    }
};