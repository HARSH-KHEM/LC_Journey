class Solution {
public:
   vector<bool>vis;
   vector<vector<int>>adj;
    void dfs(int node){
        vis[node]=true ;
        for(auto neigh : adj[node]){
            if(!vis[neigh])dfs(neigh);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vis.assign(n,false);
        adj.assign(n,{});
        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        dfs(k);
        for( auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            if(!vis[u]&&vis[v]){
                vector<int>ans;
                for( int i = 0 ; i<n ; i++)ans.push_back(i);
                return ans ;
            }
        }
        vector<int>ans ;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i])ans.push_back(i);
        }
        return ans ;
    }
};