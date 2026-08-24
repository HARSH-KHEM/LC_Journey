class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1 ;
        for(auto x:coins){
            for( int amt = x ; amt<=amount ;amt++){            
                    dp[amt]+=(long long)dp[amt-x];               
            }
        }

        return (int)dp[amount];
    }
};