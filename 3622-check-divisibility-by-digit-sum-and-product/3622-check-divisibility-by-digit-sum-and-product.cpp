class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n ;
        long long sum = 0 ;
        long long prod = 1 ;
       while(n>0){
        int digit = n%10 ;
        sum+=digit ;
        prod*=digit;
        n=n/10;
       } 
       return temp%(sum+prod)==0 ;
    }
};