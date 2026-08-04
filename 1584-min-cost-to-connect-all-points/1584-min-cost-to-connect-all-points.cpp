class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
        int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        adj[i].push_back({wt,j});
        adj[j].push_back({wt,i});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
    vector<bool>vis(n,false);
    pq.push({0,0});
    int mincost = 0 ;
    while(!pq.empty()){
        auto [edgewt,node]=pq.top();
        pq.pop();
        if(vis[node])continue ;
        vis[node]=true ;
        mincost+=edgewt ;
        for(auto [edgeweight,neigh]:adj[node]){
            if(!vis[neigh])pq.push({edgeweight,neigh});
        }
    }
    return mincost ;
    }
};