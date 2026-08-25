class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0]=1;
        for( int rem = 1 ; rem<=target ; rem ++){
            for( auto x : nums){
                if(x<=rem)dp[rem]+=(long long)dp[rem-x];
            }
        }
        return (int)dp[target];
    }
};