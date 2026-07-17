class Solution {
public:
    int solve(int i,int prev,vector<int>& arr,vector<vector<int>>& dp){
        if(i >= arr.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int notTake = solve(i+1,prev,arr,dp);
        int take = 0;
        if(prev == -1 || arr[i]%arr[prev] == 0){
            take = 1 + solve(i+1,i,arr,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(nums.begin(),nums.end());
        solve(0,-1,nums,dp);
        vector<int> ans;
        int i = 0;
        int prev = -1;
        while(i<n){
            int notTake = solve(i+1,prev,nums,dp);
            int take = 0;
            if(prev == -1 || nums[i]%nums[prev] == 0){
                take = 1 + solve(i+1,i,nums,dp);
            }
            if(take >= notTake && (prev == -1 || nums[i]%nums[prev] == 0)){
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }
        return ans;
    }
};