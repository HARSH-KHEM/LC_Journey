class DSU{
    public :
    vector<int>parent,size ;
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
        if(u==v)return ;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        if(connections.size() < n-1)return -1 ;
        for( auto &connect : connections){
            int u = connect[0];
            int v = connect[1];
            dsu.Union(u,v);
        }
            int components = 0 ;
            for( int i = 0 ; i<n ; i++){
                if(dsu.find(i)==i)components++;
            }
        return components - 1 ;
    }
};