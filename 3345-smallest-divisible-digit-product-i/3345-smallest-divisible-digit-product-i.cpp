class Solution {
public:
    int smallestNumber(int n, int t) {
        bool found = false ;
        int ans = 0 ;
        int temp = n;
        while(!found){
            n = temp;
            int prod = 1;
            while(n > 0) {
                prod = prod * (n % 10);
                n = n / 10;
            }
            if(prod % t == 0) return temp;
            temp++;
        }
        return ans ;
    }
};