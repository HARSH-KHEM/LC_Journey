class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> s = arr;
        sort(s.begin(), s.end());
        auto it = unique(s.begin(), s.end()) ;
        s.erase(it, s.end());
        for( int i = 0 ; i<arr.size() ; i++){
            arr[i]=lower_bound(s.begin(), s.end(),arr[i])-s.begin()+1 ;
        }
        return arr ;
    }
};