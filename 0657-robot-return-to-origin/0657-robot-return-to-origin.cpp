class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(char m:moves){
            if(m == 'U'){
                y++;
            }
            else if(m == 'D'){
                y--;
            }
            else if(m == 'R'){
                x++;
            }
            else if(m == 'L'){
                x--;
            }
        }
        if(x == 0 && y == 0){
            return true;
        }
        return false;
    }
};