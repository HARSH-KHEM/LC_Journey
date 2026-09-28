class Solution {
public:
    int maxDepth(string s) {
        stack<char>st ;
        int ans = 0 ;
        for(auto c:s){
            if(c=='('){
            st.push(c);
            int i = st.size() ;
            ans=max(ans,i);
            }
            if(c==')')st.pop();  
        }
       return ans ;
    }
};