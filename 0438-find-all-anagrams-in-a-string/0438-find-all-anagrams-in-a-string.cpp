class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        vector<int>ans;
        if(p.size()>s.size())return {};
        for( auto c : p){
            freq1[c-'a']++;
        }
        int m = p.size();
        int left = 0 , right = left + m ;
        for( int i = left ; i<right ;i++){
            freq2[s[i]-'a']++;
        }
        if(freq1==freq2)ans.push_back(left);
        while(right<s.size()){
            freq2[s[left]-'a']--;
            left++;
            freq2[s[right]-'a']++;
            right++;
            if(freq1==freq2)ans.push_back(left);
        }
        return ans ;
    }
};