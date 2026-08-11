class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1)return nums[0];
        int next1 = 0 , next2 = 0 ;
        int ans1 , ans2 ;
        for( int i = n-1 ; i>0 ; i--){
            int curr = max(next2+nums[i],next1);
            next2 = next1 ;
            next1 = curr ;
        }
        ans1 = max(next1,next2);
        next1 = 0 , next2 = 0 ;
        for( int i = n-2 ; i>=0 ; i--){
            int curr = max(next2+nums[i],next1);
            next2 = next1 ;
            next1 = curr ;
        }
        ans2 = max(next1,next2);
        return max(ans1,ans2);
    }
};