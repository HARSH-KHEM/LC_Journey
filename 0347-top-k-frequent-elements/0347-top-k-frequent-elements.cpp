class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;
        for(auto x : nums){
            mp[x]++;
        }
        vector<pair<int,int>>freq ;
        for(auto &p : mp){
            freq.push_back({p.first,p.second});
        }
        vector<int>ans ;
        while(k--){
            int idx = 0 ;
            for( int i = 1 ; i<freq.size() ; i++){
                if(freq[i].second > freq[idx].second)idx = i ;
            }
            ans.push_back(freq[idx].first);
            freq[idx].second = -1 ;
        }
        return ans ;
    }
};