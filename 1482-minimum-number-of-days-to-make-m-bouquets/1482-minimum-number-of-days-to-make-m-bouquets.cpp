class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k , int day){
        int cnt = 0 ; 
        int b = 0 ;
        for(auto x : bloomDay){
            if(x<=day){
                cnt++ ;
                if(cnt==k){
                    b++;
                    cnt=0;
                }
            }
            else{
                cnt = 0 ;
            }
        }
        return b>=m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ;
        if(n<(long long )m*k)return -1 ;
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        int l = 1 ;
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(bloomDay, m , k , mid ))h=mid;
            else l = mid+1;
        }
        return l ;
    }
};