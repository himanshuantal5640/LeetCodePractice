class Solution {
public:
    string reverseWords(string s) {
        vector<string> st;
        int n = s.size();
        int i = 0;
        while(i < n){
            while(i<n && s[i] == ' '){
                i++;
            }
            string w = "";
            while(i<n && s[i] != ' '){
                w += s[i];
                i++;
            }
            if(!w.empty()){
                st.push_back(w);
            }
        }

        string ans = "";
        for(int j = st.size()-1;j>=0;j--){
            ans += st[j];
            if(j != 0){
                ans += ' ';
            }
        }
        return ans;
    }
};