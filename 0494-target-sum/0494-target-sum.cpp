class Solution {
public:
    int helper(int i,int tar,vector<vector<int>> &dp,vector<int> &nums){
        if(i >= nums.size()){
            return tar == 0 ? 1 : 0;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = helper(i+1,tar,dp,nums);
        int take = 0;
        if(tar >= nums[i]){
            take = helper(i+1,tar-nums[i],dp,nums);
        }
        return dp[i][tar] = take + notTake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int n:nums){
            sum += n;
        }
        if(abs(target) > sum ){
            return 0;
        }
        if((target + sum) %2 != 0){
            return 0;
        }
        int newTar = (target + sum)/2;
        vector<vector<int>> dp(n,vector<int>(newTar+1,-1));
        return helper(0,newTar,dp,nums);
    }
};