class Solution {
public:
    bool check(vector<int>& dist, double hour , int mid){
        double hrs = 0 ;
        for( int i = 0 ; i<dist.size()-1 ;i++){
            hrs+=ceil((double)(dist[i])/mid) ;
        }
        hrs+=double(dist[dist.size()-1])/mid ;
        return hrs<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour<=dist.size()-1)return -1 ;
        int l = 1 ;
        int h = 1e7 ;
        while(l<h){
            int mid = l+(h-l)/2 ;
            if(check(dist,hour,mid))h=mid;
            else l = mid+1;
        }
        return l ;
    }
};