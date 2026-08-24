class Solution {
public:
    vector<vector<int>>dp ;
    int solve(int indx , int amt , vector<int>&coins){
        if(amt==0)return 1 ;
        if(indx == coins.size())return 0 ;
        if(dp[indx][amt]!=-1)return dp[indx][amt];
        int take = 0;
        if(coins[indx]<=amt){
            take += solve(indx , amt - coins[indx],coins);}
        int skip = solve(indx+1 , amt , coins);
        return dp[indx][amt]=take + skip ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};