class Solution {
public:
    bool solve(int i,int tar,vector<int>& nums,vector<vector<int>>& dp){
        if(i >= nums.size()){
            return false;
        }
        if(tar == 0){
            return true;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        bool notTake = solve(i+1,tar,nums,dp);
        bool take = false;
        if(tar >= nums[i]){
            take = solve(i+1,tar-nums[i],nums,dp);
        }
        return dp[i][tar] = take || notTake;
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
        int s = sum/2;
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        return solve(0,s,nums,dp);
    }
};