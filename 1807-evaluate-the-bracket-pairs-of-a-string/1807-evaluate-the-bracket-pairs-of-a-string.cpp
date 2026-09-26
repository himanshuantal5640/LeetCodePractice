class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto &p : knowledge) {
            mp[p[0]] = p[1];
        }
        string a;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '(') {
                a += s[i];
            }
            else {
                i++;
                string key;
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }
                // Replace key
                if(mp.count(key)) {
                    a += mp[key];
                }
                else {
                    a += "?";
                }
            }
        }
        return a;
    }
};