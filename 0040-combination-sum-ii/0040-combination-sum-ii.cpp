class Solution {
public:
    void solve(int idx,vector<int>& arr,int tar,vector<int>& combine,vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(combine);
            return;
        }
        for(int i = idx;i<arr.size();i++){
            if(i > idx && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > tar){
                break;
            }
            combine.push_back(arr[i]);
            solve(i+1,arr,tar-arr[i],combine,ans);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> combine;
        solve(0,candidates,target,combine,ans);
        return ans;
    }
};