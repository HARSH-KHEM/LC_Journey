class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(51, 0);
        for( int i = 0 ; i<=n-k ; i++){
            vector<int>seen(51,0);
            for( int j = i ; j<i+k ; j++){
                seen[nums[j]]=true ;
            }
            for( int x = 0 ; x<=50 ; x++){
                if(seen[x])cnt[x]++;
            }
        }
    
    for( int i = 50 ; i>=0 ;i--){
        if(cnt[i]==1)return i;
    }
    return -1 ;
    }
};