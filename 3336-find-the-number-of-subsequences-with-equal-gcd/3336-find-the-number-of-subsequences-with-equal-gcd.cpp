class Solution {
public:
     int MOD = 1e9 + 7 ;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size() ;
        int maxel = *max_element(nums.begin(),nums.end());
        vector<vector<int>>prev(maxel+1 , vector<int>(maxel +1 , 0));
        for( int first = 0 ; first<=maxel ; first++){
            for( int second = 0 ; second<=maxel ;second++){
                bool bothnonempty = (first!=0)&&(second!=0);
                bool gcdmatch = (first == second);
                prev[first][second]= (bothnonempty && gcdmatch)? 1 : 0 ;
            }
        }
        for( int i = n-1 ; i>=0 ; i--){
            vector<vector<int>>curr(maxel+1 , vector<int>(maxel+1,0));
                for( int first = maxel ; first>=0 ; first--){
                    for( int second = maxel ; second>=0 ; second--){
                        int skip = prev[first][second];
                        int take1 = prev[__gcd(first,nums[i])][second];
                        int take2 = prev[first][__gcd(second,nums[i])];
                        curr[first][second]=(0LL + skip + take1 + take2)%MOD ;

                    }
                }
                prev = move(curr);
        }
            return prev[0][0];
    }
};