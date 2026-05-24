class Solution {
public:
    bool isPalindromic(string s1){
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
    void solve(int idx,string s,int n,vector<string>& curr,vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int j=idx;j<n;j++){
            temp += s[j];
            if(isPalindromic(temp)){
                curr.push_back(temp);
                solve(j+1,s,n,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        solve(0,s,n,curr,ans);
        return ans;
    }
};