class Solution {
public:
    bool check(vector<int>& nums, int k , int mid){
        long long cnt = 0 ;
        int l = 0 ;
        for( int r = 1 ; r<nums.size() ; r++){
            while(nums[r]-nums[l]>mid)l++;
            cnt+=r-l;
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0 ;
        int h = nums[n-1] - nums[0];
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(nums,k,mid))h=mid;
            else l=mid+1 ;
        }
        return l ;
    }
};