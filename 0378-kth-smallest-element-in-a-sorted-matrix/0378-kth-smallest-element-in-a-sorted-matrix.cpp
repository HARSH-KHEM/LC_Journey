class Solution {
public:
    bool check(vector<vector<int>>& mat, int k,int mid){
        int cnt = 0 ;
        for( int i = 0 ; i<mat.size() ; i ++){
            for( int j = 0 ; j<mat[0].size() ; j++){
                if(mat[i][j]<=mid)cnt++;
            }
        }
        return cnt>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = matrix[0][0];
        int h = matrix[n-1][m-1];
        while(l<h){
            int mid = l + (h-l)/2 ;
            if(check(matrix,k,mid))h=mid;
            else l = mid+1;
        }
        return l;
    }
};