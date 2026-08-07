class Solution {
public:
    int check(int n){
        int prod = 1 ;
        while(n>0){
            int digit = n%10 ;
            prod*=digit;
            n=n/10;
        }
        return prod ;
    }
    int smallestNumber(int n, int t) {
        for(int i = n ; i <n+10 ; i++){
            if(check(i)%t==0)return i ;
        }
        return - 1 ;
    }
};