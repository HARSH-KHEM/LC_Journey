class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<pair<int,int>>freq ;
        for(int i = 0 ; i<n ; i++){
            bool ap = false ;
            for(auto p : freq){
                if(p.first == nums[i]){
                    ap = true ;
                    break ;
                }
            }
            if(ap)continue ;
            int cnt = 0 ;
            for(int j = 0 ; j<n ; j++){
                if(nums[j]==nums[i]){
                    cnt++ ;
                }
            }
            freq.push_back({nums[i],cnt});
        }

        vector<int>ans ;
        while(k--){
        int idx = 0 ;
        for( int i = 1 ; i<freq.size() ; i++){
         if(freq[i].second>freq[idx].second) idx = i ;
        }
         ans.push_back(freq[idx].first);
         freq[idx].second=-1 ;
        }
        return ans ;
    }
};