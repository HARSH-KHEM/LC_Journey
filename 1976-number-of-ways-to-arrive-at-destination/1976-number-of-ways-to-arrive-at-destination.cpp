class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>>adj(n);
        for( auto &road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adj[u].push_back({v,wt}) ;
            adj[v].push_back({u,wt}) ;
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({dist[0],0});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            if(d>dist[node])continue ;
            for( auto [neigh,wt]:adj[node]){
                long long newdist = d + wt ;
                if(newdist<dist[neigh]){
                    dist[neigh]=newdist;
                    ways[neigh]=ways[node];
                    pq.push({dist[neigh],neigh});
                }else if(newdist==dist[neigh]){
                    ways[neigh] = (ways[neigh]+ways[node])%MOD ;
                }
            }
        }
     return ways[n-1]%MOD ;
    }
};