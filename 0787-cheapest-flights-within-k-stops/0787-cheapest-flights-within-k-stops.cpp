class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int ct = flight[2];
            adj[u].push_back({v,ct});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [cos , node,flightused] = pq.top();
            pq.pop();
            if(cos>dist[node][flightused])continue ;
            if(flightused==k+1)continue ;
            for(auto &[neigh,price]:adj[node]){
                int newprice = price + cos ;
                int newflights = flightused+1;
                if(newprice<dist[neigh][newflights]){
                    dist[neigh][newflights]=newprice ;
                    pq.push({dist[neigh][newflights],neigh,newflights});
                }
            }
        }
        int ans = INT_MAX ;
        for( int i = 0 ; i<=k+1;i++){
            ans=min(ans,dist[dst][i]);
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};