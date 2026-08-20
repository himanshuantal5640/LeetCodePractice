class Solution {
public:
    bool isPalindrome(string& s1){
        int l = 0;
        int r = s1.size() - 1;
        while(l <= r){
            if(s1[l] != s1[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int idx,string& s,vector<string>& re,vector<vector<string>>& ans){
        if(idx == s.size()){
            ans.push_back(re);
            return;
        }
        string temp = "";
        for(int i = idx;i < s.size();i++){
            temp += s[i];
            if(isPalindrome(temp)){
                re.push_back(temp);
                solve(i+1,s,re,ans);
                re.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> re;
        solve(0,s,re,ans);
        return ans;
    }
};