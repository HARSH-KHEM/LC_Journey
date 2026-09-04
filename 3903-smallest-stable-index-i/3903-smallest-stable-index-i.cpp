class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0];
        for( int i = 0 ; i<nums.size() ; i++){
        int mini = INT_MAX ;
            maxi = max(maxi,nums[i]);
            for( int j = i ; j<nums.size() ; j++){
            mini = min(mini,nums[j]);
            }
            int score = maxi - mini ;
            if(score<=k)return i ;
            }
            return -1 ;
    }
};