class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++){
                if(nums[i] > nums[p]){
                    if(dp[p]+1 > dp[i]){
                        dp[i] = dp[p] + 1;
                        cnt[i] = cnt[p];
                    }
                    else if(dp[p]+1 == dp[i]){
                        cnt[i] += cnt[p];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans += cnt[i];
            }
        }
        return ans;
    }
};