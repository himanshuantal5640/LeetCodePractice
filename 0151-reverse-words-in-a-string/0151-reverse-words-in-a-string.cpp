class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        int j = 0;
        while(i<n){
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i >= n){
                break;
            }
            if(j>0){
                s[j++] = ' ';
            }
            while(i<n && s[i] != ' '){
                s[j++] = s[i++];
            }
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        int st = 0;
        for(int e=0;e<=s.size();e++){
            if(e == s.size() || s[e] == ' '){
                reverse(s.begin()+st, s.begin()+e);
                st = e + 1;
            }
        }
        return s;
    }
};