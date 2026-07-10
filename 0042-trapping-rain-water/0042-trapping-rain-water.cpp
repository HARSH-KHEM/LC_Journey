class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int l = 0 , r = n-1 ;
        int water = 0 ;
        int leftmax = height[l] , rightmax = height[r];
        while(l<r){
            if(leftmax<rightmax){
                water += leftmax - height[l];
                l++;
                leftmax=max(leftmax,height[l]);
            }else{
                water += rightmax - height[r];
                r--;
                rightmax = max(rightmax,height[r]);
            }
        }
        return water ;
    }
};