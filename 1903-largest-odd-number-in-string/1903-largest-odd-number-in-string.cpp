class Solution {
public:
    string largestOddNumber(string num) {
        //traverse for last i.e right to left
        for(int i=num.size()-1;i>=0;i--){
            //convert char into digit
            int digit = num[i] - '0';
            if(digit%2 == 1){
                //odd
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};