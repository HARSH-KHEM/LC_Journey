class Solution {
public:
    bool possible(vector<int>& piles, int h , int speed){
        long long hours = 0 ;
        for(auto p : piles){
            hours+=ceil((double)p/speed);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ;
        int l = 1 , high = *max_element(piles.begin(),piles.end()) ;
        while(l<high){
            int mid = l + (high-l)/2 ;
            if(possible(piles,h,mid))high=mid;
            else l = mid+1;
        }
        return l ;
    }
};