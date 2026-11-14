class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size() ;
        vector<int>pre(n+1 , 0 );
        for( int i = 0 ; i<n ; i++){
            pre[i+1] = pre[i]+nums[i];
        }
        int best = INT_MAX ;
        for( int j = l ; j<=n ; j++){
            for( int k = l ; k<=min(r,j) ; k++){
                int sum = pre[j] - pre[j-k];
                if(sum>0 && sum<best)best = sum ;
            }
        }
     return best == INT_MAX ? -1 : best ;
    }
};