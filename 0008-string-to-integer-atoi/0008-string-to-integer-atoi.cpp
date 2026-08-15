class Solution {
public:
    int solve(int i,string& s,long long num,int sign){
        //base
        if(i >= s.size() || !isdigit(s[i])){
            long long ans = num * sign;
            if(ans > INT_MAX){
                return INT_MAX;
            }
            else if(ans < INT_MIN){
                return INT_MIN;
            }
            return (int)ans;
        }
        int digit = s[i] - '0';
        //overflow
        if(num > (INT_MAX - digit)/10){
            if(sign == 1){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        num = num*10 + digit;
        return solve(i+1,s,num,sign);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        //skip space
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i == n){
            return 0;
        }
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        if(i == n || !isdigit(s[i])){
            return 0;
        }
        return solve(i,s,0,sign);
    }
};