class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int row = grid.size() ;
        int col = grid[0].size();
        vector<vector<int>>adj(row,vector<int>(col,INT_MAX));
        adj[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!pq.empty()){
        auto [wt,r,c]=pq.top();
        pq.pop();
        if(wt>adj[r][c])continue ;
        if(r==row-1 && c ==col-1)return wt ;
        if (row > 1 && col > 1 && grid[0][1] > 1 && grid[1][0] > 1)return -1;
        for( int i = 0 ; i<4 ;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<row && nc>=0 && nc<col){
                int arrivaltime = wt+1 ;
                int newtime ;
                if(arrivaltime>=grid[nr][nc]){
                    newtime = arrivaltime ;
                }
               else{
                 int diff = grid[nr][nc]-wt;
                 if(diff%2==1) newtime = grid[nr][nc];
                 else newtime = grid[nr][nc]+1;
               }
               if(newtime<adj[nr][nc]){
                adj[nr][nc]=newtime ;
                pq.push({newtime,nr,nc});
               }
            }
        }
     }
        return -1 ;
    }
};