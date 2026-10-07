class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int i, int left, int right, int balance, string &curr) {
        if (i == s.size()) {
            if (left == 0 && right == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }
        char c = s[i];
        if (c == '(') {
            if (left > 0) {
                dfs(s, i + 1, left - 1, right, balance, curr);
            }
            curr.push_back('(');
            dfs(s, i + 1, left, right, balance + 1, curr);
            curr.pop_back();
        }
        else if (c == ')') {
            if (right > 0) {
                dfs(s, i + 1, left, right - 1, balance, curr);
            }
            if (balance > 0) {
                curr.push_back(')');

                dfs(s, i + 1, left, right, balance - 1, curr);

                curr.pop_back();
            }
        }
        else {
            curr.push_back(c);
            dfs(s, i + 1, left, right, balance, curr);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {

                if (left > 0) {
                    left--;
                }
                else {
                    right++;
                }
            }
        }
        string curr = "";
        dfs(s, 0, left, right, 0, curr);
        return vector<string>(ans.begin(), ans.end());
    }
};