class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
       for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double>probab(n,0);
        probab[start_node]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({probab[start_node],start_node});
        while(!pq.empty()){
            auto [pro,node]=pq.top();
            pq.pop() ;
            if(pro<probab[node])continue ;
            for( auto [neigh,pt] : adj[node]){
                double newprob = pro*pt ;
                if(newprob>probab[neigh]){
                    probab[neigh]=newprob ;
                    pq.push({probab[neigh],neigh});
                }
            }
        }
        return probab[end_node];

    }
};