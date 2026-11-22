class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == 'b') {
                while (i < n) {
                    if (s[i] == 'a') {
                        return false;
                    }
                    i++;
                }
            }
            i++;
        }
        return true;
    }
};