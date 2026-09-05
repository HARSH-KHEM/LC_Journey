class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int>prefix(n) ;
        prefix[0]=nums[0];
        for( int i = 1 ; i<nums.size() ; i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        vector<int>suffix(n) ;
        suffix[n-1]=nums[n-1];
        for( int i = n-2 ; i>=0 ;i--){
            suffix[i]=min(nums[i],suffix[i+1]);
        }
        for( int i = 0 ; i<n ; i++){
            int score = prefix[i] - suffix[i];
            if(score<=k)return i ;
        }
        return -1 ;
    }
};