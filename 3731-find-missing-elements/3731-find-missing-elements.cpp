class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums){
        int n = nums.size() ;
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>ans ;
        int mini = INT_MAX , maxi = INT_MIN ;
        for( auto x : nums){
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        for( int i = mini ; i<=maxi ; i++){
            if(!st.count(i))ans.push_back(i);
        }
        return ans ;
    }
};