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

    void buildParent(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }

    TreeNode* findNode(TreeNode* root,int start){

        if(root==NULL)
            return NULL;

        if(root->val==start)
            return root;

        TreeNode* left = findNode(root->left,start);

        if(left)
            return left;

        return findNode(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*,TreeNode*> parent;

        buildParent(root,parent);

        TreeNode* source = findNode(root,start);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(source);
        vis.insert(source);

        int time = -1;

        while(!q.empty()){

            int sz = q.size();

            time++;

            while(sz--){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if(parent.count(node) && !vis.count(parent[node])){
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return time;
    }
};