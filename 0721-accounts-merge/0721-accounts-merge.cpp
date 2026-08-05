class DSU{
    public : vector<int>parent,size;
    DSU(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    for( int i = 0 ; i<=n ; i++){
        parent[i]=i;
    }
    }
    int find(int node){
        if(parent[node]==node)return node ;
        return parent[node]=find(parent[node]);
    }
    void Union( int u , int v){
        u = find(u);
        v = find(v);
        if(u ==v) return ;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }else{
            parent[v]=u;
            size[u]+=size[v];
        }
     }
    
} ;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string,int>emailtoaccount ;
        for( int i =0 ; i<accounts.size() ; i++){
            for( int j = 1 ; j<accounts[i].size() ; j++){
            string email = accounts[i][j];
            if(emailtoaccount.find(email)==emailtoaccount.end())emailtoaccount[email]=i;
            else dsu.Union(i,emailtoaccount[email]);
            }
        }
        unordered_map<int,vector<string>>merged;
        for(int i = 0; i < accounts.size(); i++){
            int leader = dsu.find(i);
            for(int j = 1; j < accounts[i].size(); j++){
        merged[leader].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(auto &[leader,emails]:merged){
            sort(emails.begin(),emails.end());
            emails.erase(unique(emails.begin(), emails.end()), emails.end());
            vector<string>temp ;
            temp.push_back(accounts[leader][0]);
            for( auto &email : emails){
                temp.push_back(email);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};