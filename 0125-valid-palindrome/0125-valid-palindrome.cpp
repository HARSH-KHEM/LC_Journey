class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n==0 || n==1 )return true ;
        string ns = "";
        for(auto c : s){
            if(!isalnum(c))continue ;
            ns+= tolower(c);
        }
        int l = 0 , r = ns.size() - 1 ;
        while(l<=r){
            if(ns[l]!=ns[r])return false ;
            l++;
            r--;
        }  
        return true ;
    }
};