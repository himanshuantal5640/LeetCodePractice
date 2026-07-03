class Solution {
public:
    int solve(int i,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(i >= arr.size()){
            return tar == 0 ? 1:0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notPick = solve(i+1,tar,arr,dp);
        int pick = 0;
        if(tar >= arr[i]){
            pick = solve(i+1,tar - arr[i],arr,dp);
        }
        return dp[i][tar] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums){
            sum += it;
        }
        if(abs(target) > sum || (sum + target)%2 != 0){
            return 0;
        }
        int newTar = (sum + target)/2;
        vector<vector<int>> dp(n+1,vector<int>(newTar+1,-1));
        return solve(0,newTar,nums,dp);
    }
};