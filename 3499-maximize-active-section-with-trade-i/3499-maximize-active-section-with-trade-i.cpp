class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size() ;
        int ones = 0 ;
        for(auto c : s){
            if(c=='1')ones++;
        }
        s= "1" + s + "1";
        vector<char>type ;
        vector<int>len ;
        char curr = s[0];
        int cnt = 1 ;
        for( int i = 1 ; i< s.size(); i++){
         if(s[i]==curr)cnt++;
         else{
            type.push_back(curr);
            len.push_back(cnt);
            curr = s[i];
            cnt = 1;
         }
        }
        type.push_back(curr);
        len.push_back(cnt);
        int best = 0 ;
        for( int i = 1 ; i<type.size()-1 ; i++){
            if(type[i]=='1' && type[i-1] == '0' && type[i+1]=='0'){
                best = max(best,len[i-1] + len[i+1]);
            }
        }
        return min(best+ones , n);
    }
};