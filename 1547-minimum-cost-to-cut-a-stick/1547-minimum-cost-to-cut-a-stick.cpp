class Solution {
public:
    int solve(int i,int j,vector<int> &c,vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int idx = i;idx <= j;idx++){
            int cost = c[j+1] - c[i-1] + solve(i,idx-1,c,dp) + solve(idx+1,j,c,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(1,m-2,cuts,dp);
    }
};