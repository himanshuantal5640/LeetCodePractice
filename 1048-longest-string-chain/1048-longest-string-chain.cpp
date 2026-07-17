class Solution {
public:
    bool isPreced(string& a,string& b){
        if(a.size() + 1 != b.size()){
            return 0;
        }
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            
        }
        return i == a.size();
    }
    int solve(int i,int prev,vector<string>& s,vector<vector<int>>& dp){
        if(i >= s.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int notTake = solve(i+1,prev,s,dp);
        int take = 0;
        if(prev == -1 || isPreced(s[prev],s[i])){
            take = 1 + solve(i+1,i,s,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //sort by length
        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.size() < b.size();
        });

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,words,dp);
    }
};