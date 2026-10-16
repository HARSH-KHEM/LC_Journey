class Solution {
    static const long long MOD = 1'000'000'007;
    vector<long long> sum, sq, lazy;
    int n;
    void apply(int idx, int l, int r, long long x) {
        long long len = r - l + 1;
        long long oldSum = sum[idx];
        sq[idx] = (sq[idx] + 2LL * x % MOD * oldSum
                   % MOD + x * x % MOD * len % MOD) % MOD;
        sum[idx] = (oldSum + x * len) % MOD;
        lazy[idx] = (lazy[idx] + x) % MOD;
    }
    void push(int idx, int l, int r) {
        if (lazy[idx] == 0 || l == r)
            return;
        int mid = l + (r - l) / 2;
        apply(2 * idx, l, mid, lazy[idx]);
        apply(2 * idx + 1, mid + 1, r, lazy[idx]);
        lazy[idx] = 0;
    }
    void update(int idx, int l, int r,
                int ql, int qr, long long x) {
        if (r < ql || qr < l)
            return;
        if (ql <= l && r <= qr) {
            apply(idx, l, r, x);
            return;
        }
        push(idx, l, r);
        int mid = l + (r - l) / 2;
        update(2 * idx, l, mid, ql, qr, x);
        update(2 * idx + 1, mid + 1, r, ql, qr, x);
        sum[idx] = (sum[2 * idx] + sum[2 * idx + 1]) % MOD;
        sq[idx] = (sq[2 * idx] + sq[2 * idx + 1]) % MOD;
    }
    long long query(int idx, int l, int r, int ql, int qr) {
        if (r < ql || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return sq[idx];
        push(idx, l, r);
        int mid = l + (r - l) / 2;
        return (query(2 * idx, l, mid, ql, qr)
              + query(2 * idx + 1, mid + 1, r, ql, qr)) % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n + 5, 0);
        sq.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.count(nums[i]))
                prev = last[nums[i]];
            update(1, 0, n - 1, prev + 1, i, 1);
            last[nums[i]] = i;
            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;
        }
        return (int)ans;
    }
};