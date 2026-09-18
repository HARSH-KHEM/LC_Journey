class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
    int n = s.size() ;
     vector<int>first(26,n);  
     vector<int>last(26,-1);
     vector<pair<int,int>>inter;
     vector<string>ans ;
     for( int i = 0 ; i<n ; i++){
        int c = s[i]-'a';
        first[c]=min(first[c],i);
        last[c]=i;
     }
     for( int c = 0 ; c<26 ; c++){
        if(last[c]==-1)continue ;
        int l = first[c];
        int r = last[c];
        bool valid = true ;
        for( int j = l ; j<=r ; j++){
            if(first[s[j]-'a']<l){
                valid = false ;
                break ;}
            else r = max(r , last[s[j]-'a']);
        }
        if(valid){
            inter.push_back({l,r});
        }
     }
     sort(inter.begin() , inter.end() , [](auto &a , auto &b){
        if(a.second != b.second)return a.second<b.second ;
        return a.first>b.first ;
     });
     int lastind = -1 ;
     for(auto &interval : inter){
        int l = interval.first ;
        int r = interval.second ; 
        if(l>lastind){
         ans.push_back(s.substr(l,r-l+1));
         lastind = r ;
        }
     }
     return ans ;
    }
};