class Solution {
public:
    int solve(int idx,int buy,int k,vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(idx >= arr.size() || k == 0){
            return 0;
        }
        if(dp[idx][buy][k] != -1){
            return dp[idx][buy][k];
        }
        int profit = 0;
        if(buy){
            profit = max(-arr[idx] + solve(idx+1,0,k,arr,dp),solve(idx+1,1,k,arr,dp));
        }
        else{
            //sell
            profit = max(arr[idx] + solve(idx+1,1,k-1,arr,dp),solve(idx+1,0,k,arr,dp));
        }
        return dp[idx][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};