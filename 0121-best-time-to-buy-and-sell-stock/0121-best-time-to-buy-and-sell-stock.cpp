class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<int>dp(n+1,0);
        int maxprice = 0 ;
        for( int i = n-1 ; i>=0 ; i--){
            int take = maxprice - prices[i];
            int skip = dp[i+1];
            dp[i]=max(skip,take);
            maxprice=max(maxprice,prices[i]);
        } 
    return dp[0] ;
    }
};