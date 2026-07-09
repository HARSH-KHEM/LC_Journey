class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n = nums.size() ;
        int l = 0 , r = n - 1 ;
        sort(nums.begin(),nums.end());
        for( int i = 0 ; i<n-2 ; i++){
            while(nums[i+1]==nums[i])continue;
            int l = i+1 , r = n-1 ;
            while(l<r){
                if(nums[l]+nums[r]> (-nums[i]))r--;
                else if ( nums[l]+nums[r]< (-nums[i]))l++;
                else{
                ans.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while(l < r && nums[l] == nums[l-1])
                 l++;
                while(l < r && nums[r] == nums[r+1])
                r--;
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};