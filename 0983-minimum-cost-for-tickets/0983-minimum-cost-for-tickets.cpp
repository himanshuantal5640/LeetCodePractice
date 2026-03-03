class Solution {
public:
    int solve(int idx,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(idx >= days.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        //1 day pass
        int op1 = costs[0] + solve(idx+1,days,costs,dp);
        //7 days pass;
        int i;
        for(i = idx;i<days.size() && days[i] < days[idx]+7;i++);
        int op2 = costs[1] + solve(i,days,costs,dp);
        // 30 days pass
        for(i = idx;i<days.size() && days[i] < days[idx]+30;i++);
        int op3 = costs[2] + solve(i,days,costs,dp);
        dp[idx] = min(op1,min(op2,op3));
        return dp[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return solve(0,days,costs,dp);
    }
};