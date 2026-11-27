class Solution {
public:
    bool canAliceWin(int n) {
        int t = 10 , i=0 ;
        while(n>=t){
            n-=t;
            t--;
            i++;
        }
        return i%2==1;
    }
};