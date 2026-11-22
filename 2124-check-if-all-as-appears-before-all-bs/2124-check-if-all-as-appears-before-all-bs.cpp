
class Solution {
public:
    bool checkString(string s) {
        int fa = -1, fb = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') fa = max(fa, i);

            if(s[i] == 'b' && fb == -1) {
                fb = i;
            }
        }
        return fb == -1 || fb > fa;
    }
};
