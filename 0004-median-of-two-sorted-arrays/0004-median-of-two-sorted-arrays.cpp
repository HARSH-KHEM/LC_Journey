class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())return findMedianSortedArrays(b,a);
        int n = a.size() ;
        int m = b.size() ;
        int l = 0 ;
        int h = n ; 
        while(l<=h){
            int x = l+(h-l)/2 ;
            int y = (m+n+1)/2 - x ;
            int l1 = x==0 ? INT_MIN : a[x-1];
            int r1 = x==n ? INT_MAX : a[x];
            int l2 = y==0 ? INT_MIN : b[y-1];
            int r2 = y==m ? INT_MAX : b[y];
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==1)return max(l1,l2);
                else return (max(l1,l2) + min(r1,r2))/2.0 ;
            }
            else if(l1>r2)h=x-1;
            else l=x+1;
        }
        return 0 ;
    }
};