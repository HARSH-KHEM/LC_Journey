class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0 ;
        int i = 0 , j = i+1 ;
        while(j<n){
            if(nums[i]==nums[j])j++;
            else{
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
        }
        return i+1;
    }
};