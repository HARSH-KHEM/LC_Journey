class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
                dp[i]++;
            }
        }
        vector<int> ans;
        bool used = false;
        j = 0;
        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!used) {
                int remaining = m - j - 1;

                if (dp[i + 1] >= remaining) {
                    used = true;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        if (j != m) return {};
        return ans;
    }
};