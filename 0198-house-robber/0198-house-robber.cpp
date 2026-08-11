class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next1 = 0 , next2 = 0 ;
        for( int i = n-1 ; i>=0 ; i--){
            int curr = max(nums[i]+next2 , next1);
            next2 = next1 ;
            next1 = curr ;
        }
        return max(next2,next1);
    }
};