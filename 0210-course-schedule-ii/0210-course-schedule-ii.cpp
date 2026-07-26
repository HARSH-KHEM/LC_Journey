class Solution {
public:
    vector<bool>vis ;
    vector<bool>recpath ;
    vector<int>topo ;
    vector<vector<int>>adj ;
    bool dfs(int node){
        vis[node]= true ;
        recpath[node] = true ;
        for(auto neigh : adj[node]){
          if(!vis[neigh]){
            if(dfs(neigh))return true ;
          }
          else if(recpath[neigh]) return true ;
        }
        recpath[node]= false ;
        topo.push_back(node);
        return false ;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        adj.assign(n,{});
        vis.assign(n,false);
        recpath.assign(n,false);
        for(auto &edge : pre){
           int u = edge[0];
           int v = edge[1];
           adj[v].push_back(u);
        }
       for( int i = 0 ; i<n ; i++){
        if(!vis[i]){
            if(dfs(i))return {};
        }
       }
       reverse(topo.begin(),topo.end());
       return topo ;
    }
};