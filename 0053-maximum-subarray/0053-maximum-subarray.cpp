class Solution {
public:
    int ans = INT_MIN ; 
    vector<int>dp ;
    int solve( int idx , vector<int>&nums){
        if(idx==0){
        ans = max(ans,nums[0]);
        return dp[0] = nums[0];}
        if(dp[idx]!=-1)return dp[idx];
        int previous = solve(idx-1,nums);
        int curr = max(nums[idx],nums[idx]+previous);
        ans = max(ans,curr);
        return dp[idx] = curr ;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        dp.assign(n,-1);
        solve(n-1,nums);
        return ans ;
    }
};