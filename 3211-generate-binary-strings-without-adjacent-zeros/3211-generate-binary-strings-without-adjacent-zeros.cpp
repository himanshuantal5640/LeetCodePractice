class Solution {
public:
    void solve(int n,string str,int prev,vector<string>& ans){
        if(n == str.size()){
            ans.push_back(str);
            return;
        }
        //choice 1 --> put 0
        if(prev == 1){
            solve(n,str+'0',0,ans);
        }
        solve(n,str+'1',1,ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(n,"",1,ans);
        return ans;
    }
};