class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int fs, int fe) {
        int n = oi.size() ;
        sort(oi.begin() , oi.end());
        vector<vector<int>>merged ;
        int l = oi[0][0];
        int r = oi[0][1];
        for( int i = 0 ; i<n ; i++){
            if(oi[i][0]<=r+1){
                r=max(r,oi[i][1]);
            }else{
                merged.push_back({l,r});
                l=oi[i][0];
                r=oi[i][1];
            }
        }
            merged.push_back({l,r});
        vector<vector<int>>ans ;
        for( auto &p : merged){
            int l = p[0];
            int r = p[1];
            if(r<fs|| l>fe){
                ans.push_back({l,r});
            }
            else{
                if(l<fs){
                    ans.push_back({l,fs-1});
                }
                if(r>fe){
                    ans.push_back({fe+1,r});
                }
            }
        }
        return ans ;
    }
};