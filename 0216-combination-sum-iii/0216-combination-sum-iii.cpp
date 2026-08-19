class Solution {
public:
    void solve(int st,int k,int tar,vector<int>& path,vector<vector<int>>& ans){
        if(k == 0){
            if(tar == 0){
                ans.push_back(path);
            }
            return;
        }
        if(tar < 0){
            return;
        }
        for(int i = st;i<=9;i++){
            path.push_back(i);
            solve(i+1,k-1,tar - i,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(1,k,n,path,ans);
        return ans;
    }
};