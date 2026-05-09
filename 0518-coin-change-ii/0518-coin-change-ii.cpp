class Solution {
public:
    int solve(int i,int tar,vector<int>& in,vector<vector<int>>& dp){
        if(i >= in.size()){
            return tar == 0? 1:0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = solve(i+1,tar,in,dp);
        int take = 0;
        if(tar >= in[i]){
            take = solve(i,tar - in[i],in,dp);
        }
        return dp[i][tar] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};