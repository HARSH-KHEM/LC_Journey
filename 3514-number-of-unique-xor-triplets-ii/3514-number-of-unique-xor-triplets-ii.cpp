class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        unordered_set<int> pairXor;
        unordered_set<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }
        for (int px : pairXor) {
            for (int x : nums) {
                ans.insert(px ^ x);
            }
        }
        for (int x : nums)
            ans.insert(x);

        return ans.size();
    }
};