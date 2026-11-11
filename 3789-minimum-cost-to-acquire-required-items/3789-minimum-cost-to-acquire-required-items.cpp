class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0 ;
        ans+=min(need1,need2);
        ans*=min(costBoth,cost1+cost2);
        if(need1>need2){
            ans+=(long long)abs(need1-need2)*min(costBoth,cost1) ;
        }
        else if(need2>need1){
            ans+=(long long)abs(need2-need1)*min(costBoth , cost2) ; 
        }
        return ans ;
    }
};