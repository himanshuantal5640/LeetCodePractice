class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0,high = 0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                low++;
                high++;
            }
            else if(ch==')')
            {
                low--;
                high--;
            }
            else
            {
                low--;
                high++;
            }
            if(low<0)
            {
                low=0;
            }
            if(high<low)
            {
                return false;
            }
        }
        return low==0;
    }
};