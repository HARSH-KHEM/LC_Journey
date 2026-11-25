typedef unsigned long long ull;

class Solution {
    static constexpr ull MOD = (1ULL << 61) - 1;
    vector<ull> pw, h;
    int n;
    static ull mul(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull r = (ull)(t & MOD) + (ull)(t >> 61);
        if (r >= MOD) r -= MOD;
        return r;
    }
    ull get(int l, int len) {
        ull r = h[l + len] + MOD - mul(h[l], pw[len]);
        if (r >= MOD) r -= MOD;
        return r;
    }
    bool check(int len) {
        vector<ull> v;
        v.reserve(n - len + 1);
        for (int l = 0; l + len <= n; l++) v.push_back(get(l, len));
        sort(v.begin(), v.end());
        int m = v.size();
        for (int i = 0; i < m; i++) {
            bool leftSame = (i > 0 && v[i] == v[i - 1]);
            bool rightSame = (i + 1 < m && v[i] == v[i + 1]);
            if (!leftSame && !rightSame) return true;
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull B = rng() % (MOD - 1000) + 500;

        pw.assign(n + 1, 1);
        h.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pw[i + 1] = mul(pw[i], B);
            ull x = mul(h[i], B) + nums[i];
            if (x >= MOD) x -= MOD;
            h[i + 1] = x;
        }

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};