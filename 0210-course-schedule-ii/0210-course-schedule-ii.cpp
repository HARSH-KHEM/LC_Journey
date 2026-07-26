class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto &edge : pre){
           int u = edge[0];
           int v = edge[1];
           adj[v].push_back(u);
           degree[u]++;
        }
        queue<int>q ;
        for( int i = 0 ;i<n ; i++){
            if(degree[i]==0)q.push(i);
        }
        int cnt = 0 ;
        vector<int>topo ;
        while(!q.empty()){
            int node = q.front();
            q.pop() ;
            topo.push_back(node);
            cnt++ ;
            for( auto neigh : adj[node]){
                degree[neigh]--;
                if(degree[neigh]==0)q.push(neigh);
            }
        }
            if(cnt<n)return {};
            return topo ;
    }
};