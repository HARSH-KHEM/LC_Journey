class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector< int > prefix(nums.size());
        vector< int > maxi ;
        int maxim = INT_MIN ;
        for(auto n: nums){
            maxim = max(maxim,n);
            maxi.push_back(maxim);
        }
        for( int i = 0 ; i<nums.size() ; i++){
            prefix[i]=__gcd(nums[i],maxi[i]);
        }
        int m = prefix.size() ;
        sort(prefix.begin(),prefix.end());
        int i = 0 , j = m-1 ; 
        long long sum = 0 ;
        while(i<j){
           sum+= __gcd(prefix[i],prefix[j]);
           i++;
           j--;
        }
      return sum;
    }
};