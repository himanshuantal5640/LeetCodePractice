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
            take = helper(i+1,tar - nums[i],dp,nums);
        }
        dp[i][tar] = take || notTake;
        return dp[i][tar];

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int n : nums){
            sum += n;
        }
        if(sum % 2 != 0){
            return false;
        }
        int tar = sum/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return helper(0,tar,dp,nums);
    }
};