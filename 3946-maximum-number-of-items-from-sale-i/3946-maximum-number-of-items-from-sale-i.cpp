class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
       int n = items.size() ;
       int mn = INT_MAX ;
       for( auto &x : items){
        mn = min(mn,x[1]);
       } 
       const int NEG = -1e9;
       vector<int>dp(budget+1,NEG);
       dp[0] = 0 ;
       for( int i = 0 ; i<n ; i++){
        int f = items[i][0];
        int p = items[i][1];
        int gain = 0 ;
        for( int j = 0 ; j<n ; j++){
            if(items[j][0]%f==0)gain++;
        }
        for( int b = budget ; b>=p ; b--){
            if(dp[b-p]!=NEG){
              dp[b]=max(dp[b],dp[b-p] + gain);
            }
          }
       }
        int ans = 0 ;
        for( int b = 0 ; b<=budget ; b++){
            if(dp[b]!=NEG){
                ans=max(ans,dp[b]+(budget - b)/mn);
            }
        }
       return ans ;
    }
};