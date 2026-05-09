class Solution {
public:
    int solve(int i,int buy,vector<int>& in,vector<vector<int>>& dp){
        if(i >= in.size()){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-in[i] + solve(i+1,0,in,dp),0+solve(i+1,1,in,dp));
        }
        else{
            profit = max(in[i]+solve(i+2,1,in,dp),0+solve(i+1,0,in,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};