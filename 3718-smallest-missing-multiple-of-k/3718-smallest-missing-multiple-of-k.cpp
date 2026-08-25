class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>mp ;
        for( auto x : nums){
            mp.insert(x);
        }
        int cnt = 1 ;
        while(true){
         if(mp.find(cnt*k)==mp.end())return cnt*k ;
         else cnt++;
        }
    }
};