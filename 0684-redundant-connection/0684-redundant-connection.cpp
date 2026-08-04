class DSU {
 public : 
 vector<int>parent,size;
 DSU( int n ){
    parent.resize(n+1);
    size.resize(n+1,1);
    for( int i = 0 ; i<=n ; i++){
        parent[i]=i;
      }
    }
    int find( int node){
        if(parent[node]==node)return node ;
        return parent[node]=find(parent[node]);
    }
    void Union( int u , int v){
        u = find(u);
        v = find(v);
        if(u==v)return ;
        if(size[u]<size[v]){
         parent[u]=v;
         size[v]+=size[u];
        }else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        DSU dsu(n);
        for( auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(dsu.find(u)==dsu.find(v))return edge ;
            dsu.Union(u,v);
        }
        return {};
    }
};