class Solution {
public:
    bool solve(int i,int s,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(s == 0){
            return true;
        }
        if(i >= n){
            return false;
        }
        if(dp[i][s] != -1){
            return dp[i][s];
        }
        bool notTake = solve(i+1,s,n,nums,dp);
        bool take = false;
        if(s >= nums[i]){
            take = solve(i+1,s - nums[i],n,nums,dp);
        }
        return dp[i][s] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x:nums){
            sum += x;
        }
        if(sum % 2 != 0){
            return false;
        }
        int s =sum/2;
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        return solve(0,s,n,nums,dp);
    }
};