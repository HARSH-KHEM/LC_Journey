class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits ;
        int ans = 0 ;
        while(n>0){
            int digit = n%10 ;
            digits.push_back(digit);
            n=n/10 ;
        }
        int i = 0 ;
        while(i<digits.size()-1){
            int j = i+1 ;
           while(j<digits.size()){
            ans = max(ans,digits[i]*digits[j]);
            j++ ;
           }
           i++;
        }
        return ans ;
    }
};