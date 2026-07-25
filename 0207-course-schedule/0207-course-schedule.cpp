class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for( auto &edge : pre){
            int course = edge[0];
            int pre = edge[1];
            adj[pre].push_back(course);
            degree[course]++;
        }
        queue<int>q ;
        for( int i = 0 ;i<n ;i++){
            if(degree[i]==0)q.push(i);
        }
        int cnt = 0 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            cnt++ ;
            for(auto neigh : adj[node]){
                degree[neigh]--;
                if(degree[neigh]==0)q.push(neigh);
            }
        }
        return cnt == n ;
    }
};