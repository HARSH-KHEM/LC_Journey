class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using p = pair<int,int> ;
        using t = tuple<long long , int , int > ;
        priority_queue< p , vector<p> , greater<p>>avail ;
        priority_queue< t , vector<t> , greater<t>>busy ;
        
        int n = servers.size() ;
        int m = tasks.size() ;

        for( int i = 0 ; i<n ; i++){
            avail.push({servers[i],i});
        }
        
        vector<int>ans(m);
        for( int j = 0 ; j<m ; j++){
         while(!busy.empty() && get<0>(busy.top())<=j){
            auto [ ft , wt , idx] = busy.top() ;
            busy.pop() ;
            avail.push({wt,idx});
         }
         if(!avail.empty()){
            auto [wt,idx] = avail.top() ;
            avail.pop() ;
            ans[j] = idx ;
            busy.push({j+ tasks[j] , wt , idx});
         }
         else{
            auto [ft, wt , idx] = busy.top() ;
            busy.pop() ;
            ans[j]=idx ;
            busy.push({ft + tasks[j] , wt , idx});
         }
        }
        return ans ;
    }
};