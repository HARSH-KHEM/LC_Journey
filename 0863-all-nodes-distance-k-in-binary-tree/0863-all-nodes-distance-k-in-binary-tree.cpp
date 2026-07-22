/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void buildparent(TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left]=root;
            buildparent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            buildparent(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildparent(root);
        queue<TreeNode*>q;
        unordered_set<TreeNode*>vis ;
        q.push(target);
        vis.insert(target);
        int dis = 0 ;
        while(!q.empty()){
            int sz = q.size() ;
            if(dis==k)break ;
            while(sz--){
                TreeNode * curr = q.front() ;
                q.pop() ;
                if(curr->left && !vis.count(curr->left)){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && !vis.count(curr->right)){
                    q.push(curr->right);
                    vis.insert(curr->right); 
                }
                if(parent.count(curr) && !vis.count(parent[curr])){
                     q.push(parent[curr]);
                    vis.insert(parent[curr]); 
                }
            }
            dis++ ;
        }
        vector<int>ans ;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop() ;
        }
        return ans ;
    }
};