class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size() ;
        int col = heights[0].size();
        vector<vector<int>>adj(row,vector<int>(col,INT_MAX));
        adj[0][0]=0 ;
        priority_queue<
        tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq; 
        pq.push({0,0,0});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!pq.empty()){
        auto [e,r,c]=pq.top();
        pq.pop();
        if(e>adj[r][c])continue ;
        for( int i = 0 ; i<4 ;i++){
         int nr = r + dr[i];
         int nc = c + dc[i];
         if(nr>=0 && nr<row && nc>=0 && nc<col){
            int edgediff = abs(heights[r][c]-heights[nr][nc]);   
            int neweffort = max(edgediff,e);
            if(neweffort<adj[nr][nc]){
                adj[nr][nc]=neweffort;
                pq.push({neweffort,nr,nc});
            }     
         }
       }
     }
     return adj[row-1][col-1];
    }
};