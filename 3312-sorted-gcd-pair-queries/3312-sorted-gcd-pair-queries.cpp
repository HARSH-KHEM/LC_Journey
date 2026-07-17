class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());


        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<int> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }


        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            long long totalPairs = 1LL * cnt[d] * (cnt[d] - 1) / 2;

            exact[d] = totalPairs;

            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }


        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        for (long long q : queries) {

            int gcdValue = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};