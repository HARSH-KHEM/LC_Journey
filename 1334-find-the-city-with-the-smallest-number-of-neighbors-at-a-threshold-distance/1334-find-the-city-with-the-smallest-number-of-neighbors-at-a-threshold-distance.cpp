class Solution {
public:
    const int inf = 1e9 ;
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>>dist(n,vector<int>(n,inf));
        for( int i = 0 ; i<n ; i++){
            dist[i][i]=0;
        }
        for( auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v]=wt ;
            dist[v][u]=wt;
        }
        for( int k = 0 ; k<n ; k++){
            for( int i = 0 ; i<n ; i++){
                for( int j = 0 ; j<n ; j++){
                    if(dist[i][k]==inf || dist[k][j]==inf)continue ;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int> cnt(n,0);
        for( int i = 0 ; i<n ; i++){
            for( int j = 0 ; j<n ; j++){
                if(i==j)continue ;
                if(dist[i][j]<=threshold)cnt[i]++;
            }
        }
        int ans = -1;
        int mini = inf;
        for( int i = 0 ; i<n ; i++){
            if(cnt[i]<=mini){
                mini = cnt[i];
                ans = i;}
        }
       return ans ; 
    }
};