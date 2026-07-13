class Solution {
public:
     bool check(vector<int>& time, int tT , long long mid ){
     long long trips = 0 ;
     for(auto x : time){
       trips+=mid/x;
     }
    return trips>=tT;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1 ;
        long long h = 1LL*(*min_element(time.begin(),time.end()))*totalTrips ;
        while(l<h){
            long long mid = l + (h-l)/2 ;
            if(check(time,totalTrips,mid))h=mid;
            else l = mid+1 ;
        }
        return l ;
    }
};