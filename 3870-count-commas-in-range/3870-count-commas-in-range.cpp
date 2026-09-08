class Solution {
public:
    int countCommas(int n) {
       long long ans  = 0 ;
        long long base = 1000 ;
        while(base<=n){
            ans+=(n-base+1);
            base*=1000;
        }
        return ans ;
    }
};