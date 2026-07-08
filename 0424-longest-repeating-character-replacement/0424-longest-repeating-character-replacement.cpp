class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int left = 0 ;
        int maxfreq = 0 ;
        int ans = 0 ;
        for( int r = 0 ; r<s.size() ; r++){
            freq[s[r]-'A']++;
            maxfreq = max ( maxfreq,freq[s[r]-'A']);
           while((r-left+1)-maxfreq>k){
            freq[s[left]-'A']--;
            left++;
           }
           ans = max(ans,r-left+1);
        }
        return ans ;
    }
};