class Solution {
public:
    void solve(int open,int close,string cur,int n,vector<string>& ans){
        if(cur.size() == 2*n){
            ans.push_back(cur);
            return;
        }
        if(open < n){
            solve(open+1,close,cur+"(",n,ans);
        }
        if(close < open){
            solve(open,close+1,cur+")",n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,"",n,ans);
        return ans;
    }
};