class Solution {
public:
    bool check(vector<int>&v1 , vector<int>&v2){
        for( int i = 0 ; i<128 ; i++){
            if(v2[i]<v1[i])return false ;
        }
        return true ;
    }
    string minWindow(string s, string t) {
        vector<int>freq1(128,0);
        vector<int>freq2(128,0);
        if(t.size()>s.size())return {};
        for( auto c : t ){
            freq1[c]++;
        }
        int left = 0 , start =0 , minlength = INT_MAX ;
        for( int right = 0 ; right < s.size() ; right++){
            freq2[s[right]]++;
            while(check(freq1,freq2)){
                if(right-left+1<minlength){
                    minlength = right - left + 1;
                    start = left ;
                }
                freq2[s[left]]--;
                left++;
            }
        }
        if(minlength == INT_MAX)return {};
        string ans = "" ;
        for( int i = start ; i<start+minlength ; i++){
            ans+=s[i];
        }
        return ans ;
    }
};