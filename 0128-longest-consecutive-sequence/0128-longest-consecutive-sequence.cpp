class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxlength = 0 ;
        for(auto x : st){
            if(st.find(x-1)==st.end()){
                int curr = x ;
                int length = 1 ;
                while(st.find(curr+1)!=st.end()){
                    length++;
                    curr++;
                }
                maxlength = max(maxlength,length);
            }
        }
        return maxlength ;
    }
};