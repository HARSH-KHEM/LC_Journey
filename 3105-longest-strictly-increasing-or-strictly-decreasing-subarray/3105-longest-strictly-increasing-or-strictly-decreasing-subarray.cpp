class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int i = 0;

        while(i < n) {
            int j = i;
            while(j+1 < n && nums[j+1] > nums[j]) j++;
            ans = max(ans, j-i+1);

            int k = i;
            while(k+1 < n && nums[k+1] < nums[k]) k++;
            ans = max(ans, k-i+1);

            i++;
        }
        return ans;
    }
};