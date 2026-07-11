class Solution {
public:
    bool check(vector<int>& nums, int t , int div ){
    long long sum = 0 ;
     for(auto x : nums){
        sum += ceil((double)x/div);
     }
     return (int)sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int h = *max_element(nums.begin(),nums.end());
        int l = 1 ;
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(nums,threshold,mid))h=mid ;
            else l = mid+1 ;
        }
        return l ;
    }
};