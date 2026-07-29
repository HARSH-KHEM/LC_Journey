class Solution {
public:
    const long long LIMIT = 1000000LL;
    long long comb(int n , int r ){
        if(r<0 || r>n)return 0 ;
        r = min(r,n-r);
        long long ans = 1 ;
        for( int i = 1 ; i<=r ; i++){
            ans=ans*(n-r+i)/i ;
            if(ans>LIMIT)return LIMIT+1 ;
        }
        return ans ;
    }
    long long countways(vector<int>&cnt){
        int total = 0 ;
        for( int x : cnt)total+=x;
        int remain = total ;
        long long ways = 1 ;
        for( int x : cnt){
            if(x==0)continue ;
            ways*=comb(remain,x);
            if(ways>LIMIT)return LIMIT+1 ;
            remain -=x;
        }
        return ways ;
    }
    string smallestPalindrome(string s, int k) {
        vector<int>freq(26,0);
        for(auto c: s){
            freq[c-'a']++;
        }
        vector<int>half(26) ;
        char mid = 0 ;
        int len = 0 ;
        for( int i = 0 ; i<26 ; i++){
            half[i]=freq[i]/2 ;
            len +=half[i];
            if(freq[i]%2){
                mid = char('a'+i);
            }
        }
            if (countways(half)<k) return "";
            string left = "";
            for (int pos = 0; pos < len; pos++){
            for (int c = 0; c < 26; c++){
                if (half[c] == 0)
                    continue;
                half[c]--;
                long long ways = countways(half);
                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
          }
        
        string right = left;
        reverse(right.begin(), right.end());
        if(mid)return left+mid+right;
        return left+right;
    }
};