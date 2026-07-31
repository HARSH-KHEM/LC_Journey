class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for( auto x : word){
            freq[x-'a']++;
        }
        sort(freq.rbegin() , freq.rend());
        int ans = 0 ;
        for( int i = 0 ; i<freq.size() ; i++){
            ans+=freq[i]*(i/8+1);
        }
        return ans ;
    }
};