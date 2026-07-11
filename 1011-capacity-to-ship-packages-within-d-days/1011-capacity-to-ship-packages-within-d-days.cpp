class Solution {
public:
    bool check(vector<int>&weights , int days , int cap){
    int currw = 0 ;
    int day = 1 ;
    for(auto x : weights){
        if(currw + x >cap){
        day++;
        currw = x ;
        }
        else currw+=x;
    }
    return day<=days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = weights[0];
        int sum = 0 ;
        for(auto w : weights){
            maxi=max(maxi,w);
            sum+=w;
        }
        int l = maxi , h = sum ;
        while(l<h){
            int mid = l+(h-l)/2 ;
            if(check(weights,days,mid))h=mid ;
            else l = mid+1 ;
        }
        return l ;
    }
};