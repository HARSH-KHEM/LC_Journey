class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v,wt});
        }
       vector<int>dist(n+1,INT_MAX);
       dist[k]=0 ;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({dist[k],k});
       while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        if(d>dist[node])continue ;
        for( auto [neigh,wt]:adj[node]){
            if(d+wt<dist[neigh]){
                dist[neigh]=d + wt ;
                pq.push({dist[neigh],neigh});
            }
         }  
       }
        for(int i = 1 ; i<=n ; i++){
            if(dist[i]==INT_MAX) return -1 ;
        }
        int ans = INT_MIN ;
        for( int i = 1 ; i<=n ; i++){
            ans = max(ans,dist[i]);
        }
        return ans ;
        
    }
};