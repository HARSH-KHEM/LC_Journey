class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        if(s1.size()>s2.size())return false ;
        for(auto c : s1){
            freq1[c-'a']++;
        }
        int m = s1.size();
        int out = 0 , in = out+m ;
        for( int i = out ; i<in ; i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1 == freq2)return true ;
        while(in<s2.size()){
            freq2[s2[out]-'a']--;
            out++;
            freq2[s2[in]-'a']++;
            in++;
            if(freq1==freq2) return true ;
        }
        return false ;
    }

};