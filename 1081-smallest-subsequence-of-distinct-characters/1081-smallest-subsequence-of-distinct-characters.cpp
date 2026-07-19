class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> last(26);
        vector<bool> inStack(26, false);


        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];


            if (inStack[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > c &&
                   last[st.top() - 'a'] > i) {

                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};