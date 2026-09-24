class Solution {
public:
    int check(int num){
        long long sum = 0 ;
        while(num>0){
            sum+=num%10;
            num=num/10 ;
        }
        return (int)sum ;
    }
    int smallestIndex(vector<int>& nums) {
      for( int i = 0 ; i<nums.size() ; i++){
        if(i==check(nums[i]))return i ;
      }
      return -1 ;
    }
};