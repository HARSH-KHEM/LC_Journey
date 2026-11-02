class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int med = nums[nums.size()/2];
        int moves = 0 ;
        for( auto x : nums){
            moves+=abs(med-x);
        }
        return moves ;
    }
};