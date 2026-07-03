class Solution {
public:
    int solve(int i,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(i >= arr.size()){
            return 1e9;
        }
        if(tar == 0){
            return 0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notPick = solve(i+1,tar,arr,dp);
        int pick = 1e9;
        if(tar >= arr[i]){
            pick = 1 + solve(i,tar - arr[i],arr,dp);
        }
        return dp[i][tar] = min(notPick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);
        return ans >= 1e9 ? -1:ans;
    }
};