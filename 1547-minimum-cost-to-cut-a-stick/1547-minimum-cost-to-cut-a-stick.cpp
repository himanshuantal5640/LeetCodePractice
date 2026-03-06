class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int idx = i;idx <= j;idx++){
            int cost = cuts[j+1] - cuts[i-1]
                        + solve(i,idx - 1,cuts,dp) // left
                        + solve(idx+1,j,cuts,dp); //right
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(1,m-2,cuts,dp);
    }
};