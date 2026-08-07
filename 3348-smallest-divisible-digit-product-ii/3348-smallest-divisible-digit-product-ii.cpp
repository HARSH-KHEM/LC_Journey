class Solution {
public:
    typedef long long  ll ;
     string func(ll num , int length){
        string str ;
        for( int digit = 9 ; digit>=2 ;digit-- ){
            while(num%digit==0){
                str.push_back(digit+'0');
                num/=digit;
            }
        }
        while(str.size() < length){
            str.push_back('1');
        }
        reverse(str.begin(),str.end());
        return str ; 
     }
    string smallestNumber(string num, long long t) {
        int n = num.size() ;
        ll temp = t;
        for( int primefact : {2,3,5,7}){
            while(temp%primefact==0)temp/=primefact;
        }
        if(temp!=1)return "-1" ;
        vector<ll>remaining(n+1,t);
        for( int i = 0 ; i<n ; i++){
            int digit = num[i]-'0';
            if(digit==0)break ;
            remaining[i+1]=remaining[i]/gcd(remaining[i],(ll)digit);
        }
        if(remaining[n]==1)return num ;
        int zeropos = num.find('0');
        int zeroidx = n-1 ;
        if(zeropos!=-1){
            zeroidx = zeropos;
        }
        for( int i = zeroidx ; i>=0 ; i--){
            ll required = remaining[i];
            int freeslots = n-i-1 ;
            for( int digit = (num[i]-'0') + 1; digit<=9 ; digit++){
                ll furtherreq = required/gcd(required,(ll)digit);
                string requirednum = func(furtherreq , freeslots);
                if(requirednum.size() == freeslots) return num.substr(0,i)+char(digit+'0')+requirednum ;
            }
        }
        return func(t,n+1);
    }
};