class Solution {
public:
    const int inf = 1e9 ;
    long long minimumCost(string source, string target, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<long long >>costing(26,vector<long long >(26,inf));
        
        for( int i = 0 ; i<26 ; i++)costing[i][i]=0;
        int n = o.size() ;
        for( int i = 0 ; i<n ; i++){
            int u = o[i] - 'a';
            int v = c[i] - 'a';
            int wt = cost[i];
            costing[u][v]=min(costing[u][v],(long long)wt) ;
        }
        for( int k = 0 ; k<26 ; k++){
            for( int i = 0 ; i< 26 ; i++){
                for( int j = 0 ; j<26 ; j++){
                    if(costing[i][k]==inf || costing[k][j]==inf)continue ;
                    costing[i][j]=min(costing[i][j],costing[i][k]+costing[k][j]);
                }
            }
        }
        long long ans = 0 ;
        for( int i =0 ; i<source.size() ; i++){
            int u = source[i]-'a' ;
            int v = target[i]-'a' ;
            if(costing[u][v]==inf)return-1 ;
            ans+=costing[u][v];
        }
        return ans ;
    }
};