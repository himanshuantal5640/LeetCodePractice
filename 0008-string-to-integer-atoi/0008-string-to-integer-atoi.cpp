class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        //skip space
        while(i<n && s[i] == ' '){
            i++;
        }   
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        long long ans = 0;
        while(i < n && isdigit(s[i])){
            int d = s[i] - '0';
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && d > 7)){
                if(sign == 1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            ans = ans * 10 + d;
            i++;
        }
        return ans*sign;
    }
};