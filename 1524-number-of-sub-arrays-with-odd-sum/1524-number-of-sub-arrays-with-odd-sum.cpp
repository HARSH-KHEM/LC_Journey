class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size() ;
        vector<int>pre(n+1,0);
        for( int i = 0 ; i<n ; i++){
            pre[i+1]=pre[i]+arr[i];
        }
        long long even = 0 , odd = 0 ;
        for( int i = 0 ; i<=n ; i++){
            if(pre[i]%2==0)even++;
            else odd++ ;
        }
        return  (even*odd)%1000000007;

    }
};