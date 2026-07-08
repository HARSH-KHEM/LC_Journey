class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];
            prefNum[i + 1] = prefNum[i];
            cnt[i + 1] = cnt[i];

            if (s[i] != '0') {
                prefSum[i + 1] += s[i] - '0';
                prefNum[i + 1] =
                    (prefNum[i] * 10 + (s[i] - '0')) % MOD;
                cnt[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int digits = cnt[r + 1] - cnt[l];

            long long left =
                (prefNum[l] * pow10[digits]) % MOD;

            long long num =
                (prefNum[r + 1] - left + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};