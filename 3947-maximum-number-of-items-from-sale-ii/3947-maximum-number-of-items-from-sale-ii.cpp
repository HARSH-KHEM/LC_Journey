class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size() ;
        vector<int>freq(n+1,0);
        vector<int>cnt(n+1,0);
        int mn = INT_MAX ;
        for( auto &x : items){
            freq[x[0]]++;
            mn = min(mn,x[1]);
        }
        for( int i = 1 ; i<=n ; i++){
            for(int j = i ; j<=n ; j+=i){
                cnt[i]+=freq[j];
            }
            cnt[i]--;
        }
        sort(items.begin(),items.end() , [](auto &a , auto &b){
            return a[1]<b[1];
        });
        long long ans = 0 ; 
        long long rem = budget ;
        for( auto &x : items){
            int f = x[0];
            int p = x[1];
            if(2LL*mn<=p)break ;
            if(cnt[f]==0)continue ;
            long long take = min((long long)cnt[f],rem/p);
            ans+=2*take ;
            rem-=take*p ;
        }
        ans+=rem/mn ;
        return (int)ans ;
    }
};