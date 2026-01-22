class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int m = part.size();
        for(char c:s){
            res.push_back(c);
            if(res.size()>= m && res.substr(res.size()-m,m)==part){
                res.erase(res.size()-m,m);
            }
        }
        return res;
    }
};