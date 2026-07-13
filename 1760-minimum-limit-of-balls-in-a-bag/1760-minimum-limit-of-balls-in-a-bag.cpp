class Solution {
public:
    bool check(vector<int>n , int maxop , int mid ){
        int ops = 0 ;
        for(auto x : n){
           ops +=(x-1)/mid;
        }
        return ops<=maxop ;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1 ;
        int h = *max_element(nums.begin(),nums.end());
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(nums,maxOperations , mid))h = mid ;
            else l = mid+1 ;
        }
        return l ;
    }
};