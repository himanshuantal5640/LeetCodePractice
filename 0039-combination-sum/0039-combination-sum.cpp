class Solution {
public:
    set<vector<int>> st;
    void solve(int i,int tar,vector<int>& arr,vector<int>& combine,vector<vector<int>>& ans){
        if(i >= arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(st.find(combine) == st.end()){
                ans.push_back(combine);
                st.insert(combine);
            }
        }
        combine.push_back(arr[i]);
        //include next
        solve(i+1,tar - arr[i],arr,combine,ans);
        //include same
        solve(i,tar - arr[i],arr,combine,ans);
        //exlcude
        combine.pop_back();
        solve(i+1,tar,arr,combine,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        solve(0,target,candidates,combine,ans);
        return ans;
    }
};