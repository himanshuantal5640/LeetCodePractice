class Solution {
public:
    set<vector<int>> st;
    void solve(int idx,vector<int>& arr,int tar,vector<int>& combine,vector<vector<int>>& ans){
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(st.find(combine) == st.end()){
                ans.push_back(combine);
                st.insert(combine);
            }
        }
        combine.push_back(arr[idx]);
        //single select
        solve(idx+1,arr,tar-arr[idx],combine,ans);
        //multiple select
        solve(idx,arr,tar-arr[idx],combine,ans);
        //exclude
        combine.pop_back();
        solve(idx+1,arr,tar,combine,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        solve(0,candidates,target,combine,ans);
        return ans;
    }
};