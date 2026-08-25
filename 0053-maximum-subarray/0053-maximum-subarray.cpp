class Solution {
public:
    int ans = INT_MIN ; 
    int solve( int idx , vector<int>&nums){
        if(idx==0){
        ans = max(ans,nums[0]);
        return nums[0];}
        int previous = solve(idx-1,nums);
        int curr = max(nums[idx],nums[idx]+previous);
        ans = max(ans,curr);
        return curr ;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        solve(n-1,nums);
        return ans ;
    }
};