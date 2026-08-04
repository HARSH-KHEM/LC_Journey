class DSU{
    public : vector<int>parent,size;
    DSU( int n ){
        parent.resize(n+1);
        size.resize(n+1,1);
        for( int i = 0 ; i<=n ; i++){
            parent[i]=i ;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = INT_MIN ;
        int maxcol = INT_MIN ;
        for( auto &edge : stones){
            maxrow=max(maxrow,edge[0]);
            maxcol=max(maxcol,edge[1]);
        }
        int offset = maxrow + 1 ;
        DSU dsu(maxrow+maxcol+2);
        unordered_set<int> usedNodes;
        for(auto &stone : stones){
            int row = stone[0];
            int col = stone[1] + offset;
            dsu.Union(row, col);
            usedNodes.insert(row);
            usedNodes.insert(col);
        }
       int components = 0 ;
        for(auto node : usedNodes){
            if(dsu.find(node) == node)
                components++;
        }
        return stones.size()-components ;
    }
};