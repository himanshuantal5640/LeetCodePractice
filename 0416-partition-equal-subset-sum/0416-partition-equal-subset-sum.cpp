class Solution {
public:
    bool solve(int i,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(tar == 0){
            return true;
        }
        if(i == 0){
            return false;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = solve(i-1,tar,arr,dp);
        int take = false;
        if(tar >= arr[i]){
            take = solve(i-1,tar - arr[i],arr,dp);
        }
        return dp[i][tar] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums){
            sum += it;
        }
        if(sum % 2 != 0){
            return false;
        }
        int s = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        return solve(n-1,s,nums,dp);
    }
};