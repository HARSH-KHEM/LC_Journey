class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n)return 0; 
        vector<unsigned long long> dp(n + 1);
        dp[n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            char si = s.at(i);
            for (int j = 0; j < n; j++) {
                char ti = t.at(j);
                if (si == ti) {
                    dp[j] = dp[j + 1] + dp[j];
                }
            }
        }
        return dp[0];
    }
};