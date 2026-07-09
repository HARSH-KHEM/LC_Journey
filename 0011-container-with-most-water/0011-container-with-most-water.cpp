class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxvol = 0 ;
        int n = nums.size();
        int l = 0 , r = n-1 ;
        while(l<=r){
            int cap = min(nums[l],nums[r])*(r-l);
            maxvol = max(cap,maxvol);
            if(nums[l]<nums[r])l++;
            else r--;
        }
       return maxvol ;
    }
};