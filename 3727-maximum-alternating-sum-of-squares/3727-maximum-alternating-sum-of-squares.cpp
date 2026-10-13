class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long>sq(n) ;
       for( int i = 0 ; i<n ; i++){
        sq[i]=nums[i]*nums[i];
       }
       sort(sq.begin(),sq.end());
       int idx = n/2 ;
       long long sum = 0 ;
       for( int i = 0 ; i<idx ; i++){
        sum-=sq[i];
       }
       for( int j = idx ; j <n ; j++ ){
        sum+=sq[j];
       }
        return sum ; 
    }
};