class Solution {
public:
    int solve(int idx,int buy,int fee,vector<int>& arr,vector<vector<int>>& dp){
        if(idx >= arr.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-arr[idx] + solve(idx+1,0,fee,arr,dp),solve(idx+1,1,fee,arr,dp));
        }
        else{
            //sell
            profit = max(arr[idx] - fee + solve(idx+1,1,fee,arr,dp),solve(idx+1,0,fee,arr,dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,fee,prices,dp);
    }
};