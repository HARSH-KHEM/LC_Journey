class Solution {
public:
vector<int>dp;
    int solve( int rem , vector<int>&nums){
        if(rem==0)return 1 ;
        if(rem<0) return 0 ;
        if(dp[rem]!=-1) return dp[rem];
        int ways = 0 ;
        for( int x : nums){
            if(x<=rem){
                ways+=solve(rem-x,nums);
            }
        }
        return dp[rem]=ways ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size() ;
        dp.assign(target+1,-1);
       return solve(target,nums);
    }
};