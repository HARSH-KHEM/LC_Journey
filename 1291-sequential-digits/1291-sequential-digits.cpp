class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>a;
        for( int i = 1 ; i<=9 ; i++){
            int n = i ;
            for( int j = i+1 ; j<=9 ;j++ ){
                n=n*10 + j;
                if(n>=low && n<=high)a.push_back(n);
            }
        }
        sort(a.begin(),a.end());
        return a ;
    }
};