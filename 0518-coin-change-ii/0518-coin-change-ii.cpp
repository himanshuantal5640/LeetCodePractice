class Solution {
public:
    int solve(int i,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(i >= arr.size()){
            return tar == 0 ? 1:0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notPick = solve(i+1,tar,arr,dp);
        int pick = 0;
        if(tar >= arr[i]){
            pick = solve(i,tar-arr[i],arr,dp);
        }
        return dp[i][tar] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};