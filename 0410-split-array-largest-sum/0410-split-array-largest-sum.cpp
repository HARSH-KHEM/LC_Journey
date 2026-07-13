class Solution {
public:
    bool check(vector<int>& nums, int k,int mid){
     int sum = 0 ;
     int cnt = 1 ;
     for( auto x : nums){
        if(sum+x>mid){
            cnt++ ;
            sum = x ;
        }else{
            sum+=x ;
        }
     }
     return cnt<=k ;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())return -1 ;
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(nums,k,mid))h=mid ;
            else l = mid+1;
        }
        return l ;
    }
};