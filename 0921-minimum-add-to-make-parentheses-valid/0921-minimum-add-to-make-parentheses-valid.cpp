class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int count = 0;
        int count_open = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                count_open++ ;
            }
            if(s[i] == ')'){
                if(count_open == 0){
                    count++;
                }else{
                    count_open--;
                }
            }
        }
        return count + count_open;
    }
};