class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == ')'){
                low--;
                high--;
            }
            else if(ch == '('){
                low++;
                high++;
            }
            else{
                low--;
                high++;
            }
            low = max(0,low);
            if(high < 0){
                return false;
            }
        }
        return low == 0;
    }
};