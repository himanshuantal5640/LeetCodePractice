class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }

        //double ths string s
        string doubled = s + s;

        //find doubled sustring in goal 
        return doubled.find(goal) != string::npos;//npos means no string
    }
};