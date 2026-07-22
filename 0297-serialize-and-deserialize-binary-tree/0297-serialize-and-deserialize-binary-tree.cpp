/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root , string &ans){
        if(root==NULL){ans+="#,"; return ;}
        ans += to_string(root->val) + ",";
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
       dfs(root,ans);
       return ans ; 
    }

    TreeNode* build(vector<string>&token , int &i){
        if(token[i]=="#"){
            i++;
            return NULL ;
        }
        TreeNode* root = new TreeNode(stoi(token[i]));
        i++;
        root->left = build(token , i);
        root->right = build(token , i);
        return root ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>token ;
        stringstream SS(data);
        string temp ;
        while(getline(SS,temp,',')){
            token.push_back(temp);
        }
        int i = 0 ;
        return build(token , i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));