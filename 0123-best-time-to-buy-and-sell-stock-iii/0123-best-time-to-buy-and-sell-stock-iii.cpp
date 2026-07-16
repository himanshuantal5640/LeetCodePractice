class Solution {
public:
    int solve(int idx,int buy,int cap,vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(idx >= arr.size() || cap == 0){
            return 0;
        }
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }
        int profit = 0;
        if(buy){
            profit = max(-arr[idx] + solve(idx+1,0,cap,arr,dp),solve(idx+1,1,cap,arr,dp));
        }
        else{
            profit = max(arr[idx] + solve(idx+1,1,cap-1,arr,dp),solve(idx+1,0,cap,arr,dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};