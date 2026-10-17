class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ;
        vector<array<int,3>> v;
        int i = 0 ;
        for (int x : nums) {
            int temp = x, sum = 0;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            v.push_back({sum, x , i});
            i++ ;
        }
        sort(v.begin(), v.end());
        vector<int>p(n) ;
        for( int i = 0 ; i<n ; i++){
            p[i]=v[i][2];
        }
        vector<bool>vis(n,false);
        int swaps = 0 ; 
        for( int i = 0 ; i<n ; i++){
            if(vis[i] || p[i]==i)continue ;
            int cycle = 0 ; 
            int j = i ;
            while(!vis[j]){
                vis[j]=true ;
                j=p[j];
                cycle++;
            }
            swaps += cycle - 1 ;
        }
        return swaps ;
    }
};