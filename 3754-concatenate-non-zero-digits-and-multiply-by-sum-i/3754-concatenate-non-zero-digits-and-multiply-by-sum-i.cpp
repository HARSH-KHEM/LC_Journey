class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = to_string(n);
        string x = "";
        for(int i = 0 ;i<num.size() ;i++){
            if(num[i]!='0')x.push_back(num[i]);
        }
        if(x.empty())return 0 ;
        int sum = 0;
        for( int i = 0 ; i<x.size();i++){
            char ch = x[i];
            sum+=(ch - '0');
        }
        int y = stoi(x);
        long long ans = (long long)y*sum;
        return ans ;
        
    }
};