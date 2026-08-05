class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,char> mp1;//s->t
        unordered_map<char,char> mp2;//t->s
        for(int i=0;i<s.size();i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2){
                return false;
            }
            if(mp2.find(ch2) != mp1.end() && mp2[ch2] != ch1){
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};