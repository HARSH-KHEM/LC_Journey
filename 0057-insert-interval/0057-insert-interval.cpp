class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
        vector<vector<int>>merge ;
        int i = 0 , n = interval.size() ;
        while(i<n && interval[i][1]<newinterval[0]){
            merge.push_back(interval[i]);
            i++;
        }
        while(i<n && interval[i][0]<=newinterval[1]){
            newinterval[0]=min(newinterval[0],interval[i][0]);
            newinterval[1]=max(newinterval[1],interval[i][1]);
            i++;
        }
        merge.push_back(newinterval);
        while(i<n){
            merge.push_back(interval[i]);
            i++;
        }
        return merge ;
    }
};