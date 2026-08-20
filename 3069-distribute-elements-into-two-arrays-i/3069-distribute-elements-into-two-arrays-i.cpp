class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        stack<int>st1,st2 ;
        st1.push(nums[0]);
        st2.push(nums[1]);
        for( int i = 2 ; i<nums.size(); i++){
            if(st1.top() > st2.top())st1.push(nums[i]);
            else st2.push(nums[i]);
        }
        vector<int>result ;
        while(!st2.empty()){
            int temp = st2.top();
            result.push_back(temp);
            st2.pop();
        }
        while(!st1.empty()){
            int temp = st1.top();
            result.push_back(temp);
            st1.pop();
        }
        reverse(result.begin(),result.end());
        return result ;
    }
};