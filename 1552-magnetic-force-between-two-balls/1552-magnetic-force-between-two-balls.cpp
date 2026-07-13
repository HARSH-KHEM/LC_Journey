class Solution {
public:
    bool check(vector<int>& position, int m,int mid){
        int cnt = 1 ;
        int n = position.size();
        int last = position[0];
        for(int i = 1 ; i<n ; i++){
            if(position[i]-last>=mid){
            cnt++;
            last = position[i];
        }
        }
        return cnt>=m ;
        
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1 ;
        int h = position[n-1]-position[0];
        while(l<=h){
            int mid = l+(h-l)/2 ;
            if(check(position,m,mid))l=mid+1;
            else h = mid-1 ;
        }
        return h;
    }
};