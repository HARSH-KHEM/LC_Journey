class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> d(n);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            d[i] = abs((long long)nums1[i] - nums2[i]);
            total += d[i];
        }

        long long k = (long long)k1 + k2;

        if (k >= total) {
            return 0;
        }

        sort(d.begin(), d.end());

        long long lo = 0, hi = d.back();

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long cost = 0;

            for (long long x : d) {
                if (x > mid)
                    cost += x - mid;
            }

            if (cost <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long level = lo;
        long long used = 0;

        for (long long x : d) {
            if (x > level)
                used += x - level;
        }

        long long remaining = k - used;

        for (int i = 0; i < n; i++) {
            d[i] = min(d[i], level);
        }

        for (int i = n - 1; i >= 0 && remaining > 0; i--) {
            if (d[i] > 0) {
                d[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long x : d) {
            ans += x * x;
        }

        return ans;
    }
};