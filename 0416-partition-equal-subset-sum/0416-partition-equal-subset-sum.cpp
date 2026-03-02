class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n:nums){
            sum += n;
        }
        if(sum%2 != 0){
            return false;
        }
        int tar = sum/2;
        vector<bool> dp(tar+1,false);
        dp[0] = true;
        for(int n: nums){
            for(int j = tar;j>=n;j--){
                dp[j] = dp[j] || dp[j-n];
            }
        }
        return dp[tar];
    }
};