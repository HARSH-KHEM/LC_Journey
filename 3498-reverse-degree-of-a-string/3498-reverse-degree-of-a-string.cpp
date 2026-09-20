class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>rev;
        int revstart = 26 ;
        for( char c = 'a' ; c<='z' ; c++){
            rev[c]=revstart ;
            revstart--;
        }
        long long sum = 0 ;
        for( int i = 0 ; i<s.size() ; i++){
            sum+=(i+1)*rev[s[i]];
        }
        return (int)sum ;
    }
};