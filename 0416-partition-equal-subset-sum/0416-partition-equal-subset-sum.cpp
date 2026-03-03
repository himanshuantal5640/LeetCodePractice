class Solution {
public:
    bool helper(int i,int tar,vector<vector<int>> &dp,vector<int> &nums){
        if(i >= nums.size()){
            return false;
        }
        if(tar == 0){
            return true;
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        bool notTake = helper(i+1,tar,dp,nums);
        bool take = false;
        if(tar >= nums[i]){
            take = helper(i+1,tar-nums[i],dp,nums);
        }
        return dp[i][tar] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int n:nums){
            sum += n;
        }
        if(sum % 2 != 0){
            return false;
        }
        int s = sum/2;
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        return helper(0,s,dp,nums);
    }
};