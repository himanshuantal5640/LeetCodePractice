class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp,int &maxi){
        if(i >= nums1.size() || j >= nums2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int len = 0;
        if(nums1[i] == nums2[j]){
            len = 1 + solve(i+1,j+1,nums1,nums2,dp,maxi);
            maxi = max(maxi,len);
        }
        else{
            len = 0;
        }
        dp[i][j] = len;
        solve(i+1,j,nums1,nums2,dp,maxi);
        solve(i,j+1,nums1,nums2,dp,maxi);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 0;
        solve(0,0,nums1,nums2,dp,maxi);
        return maxi;
    }
};