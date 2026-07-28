class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<vector<int>>rev(n);
        vector<int>degree(n);
        for( int node = 0 ; node < n ; node++){
            degree[node]=graph[node].size();
            for(auto neigh : graph[node]){
                rev[neigh].push_back(node);
            }
        }
        queue<int>q ;
        for( int node = 0 ; node<n ; node++){
            if(degree[node]==0)q.push(node);
        }
        vector<int>ans ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node);
            for(auto neigh : rev[node]){
                degree[neigh]--;
                if(degree[neigh]==0)q.push(neigh);
            }
        }
        sort(ans.begin() , ans.end());
        return ans ;
    }
};