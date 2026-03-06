class Solution {
public:
    int solve(int i,int j,vector<int> &c, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxi = INT_MIN;
        for(int idx = i;idx <= j;idx++){
            int cost = c[i-1]*c[idx]*c[j+1] + solve(i,idx-1,c,dp) + solve(idx+1,j,c,dp);
            maxi = max(cost,maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);    
    }
};