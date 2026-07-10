class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int>st ;
        vector<int>right(n,0);
        vector<int>left(n,0);
        for(int i = n-1 ; i>=0 ;i--){
           while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
           if(st.empty())right[i]=n;
           else right[i]= st.top();
           st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = 0 ; i<n ;i++){
           while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
           if(st.empty())left[i]=-1;
           else left[i]= st.top();
           st.push(i);
        }

        int ans = 0 ;
        for( int i = 0 ; i<n ; i++){
           ans=max(ans,nums[i]*(right[i]-left[i]-1));
            }
            return ans ;  
    }
};