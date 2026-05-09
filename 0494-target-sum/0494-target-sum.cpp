class Solution {
public:
    int solve(int i,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(i >= nums.size()){
            return tar == 0 ? 1:0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = solve(i+1,tar,nums,dp);
        int take = 0;
        if(tar >= nums[i]){
            take = solve(i+1,tar-nums[i],nums,dp);
        }
        return dp[i][tar] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int x:nums){
            sum += x;
        }
        if(abs(target) > sum || (sum+target)%2 != 0){
            return 0;
        }
        int newTar = (sum + target)/2;
        vector<vector<int>> dp(n,vector<int>(newTar+1,-1));
        return solve(0,newTar,nums,dp);
    }
};