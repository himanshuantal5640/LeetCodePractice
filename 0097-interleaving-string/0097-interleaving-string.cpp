class Solution {
public:
    bool solve(int i,int j,string s1, string s2, string s3,vector<vector<int>>& dp){
        if(i == s1.size() && j == s2.size()){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int k = i + j;
        bool ans = false;
        //take from s1
        if(i < s1.size() && s1[i] == s3[k]){
            ans = ans || solve(i+1,j,s1,s2,s3,dp);
        }
        //take from s2
        if(j < s2.size() && s2[j] == s3[k]){
            ans = ans || solve(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        if(n + m != p){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};