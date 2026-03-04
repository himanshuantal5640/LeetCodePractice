class Solution {
public:
    int solve(int i,int tar,vector<int>& coins,vector<vector<int>> &dp){
        if(tar == 0){
            return 0;
        }
        if(i == coins.size()){
            return 1e9;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = solve(i+1,tar,coins,dp);
        int take = 1e9;
        if(coins[i] <= tar){
            take = 1 +  solve(i,tar - coins[i],coins,dp);
        }
        return dp[i][tar] =  min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};