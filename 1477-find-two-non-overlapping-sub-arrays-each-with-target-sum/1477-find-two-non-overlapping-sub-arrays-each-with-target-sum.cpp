class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size() ;
        vector<int>best(n+1,INT_MAX);
        int sum = 0 , left = 0 , ans = INT_MAX ;
        for( int right = 0 ; right<arr.size() ; right++){
            sum+=arr[right];
            while(sum>=target){
                if(sum==target){
                    int len = right - left + 1 ;
                    if(best[left]!=INT_MAX){ans = min(ans,best[left]+len);}
                    best[right+1]=min(best[right+1],len);
                }
                sum-=arr[left];
                left++;
            }
            best[right+1]=min(best[right+1],best[right]);
        }
        return ans==INT_MAX ? -1:ans ;
    }
};