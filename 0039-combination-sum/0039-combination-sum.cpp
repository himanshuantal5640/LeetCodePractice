class Solution {
public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& arr,int idx,int tar,vector<int> &combine,vector<vector<int>> &ans){
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(s.find(combine) == s.end()){
                ans.push_back(combine);
                s.insert(combine);
            }
        }
        combine.push_back(arr[idx]);
        //single select
        getAllCombinations(arr,idx+1,tar-arr[idx],combine,ans);
        //multilple select
        getAllCombinations(arr,idx,tar-arr[idx],combine,ans);
        //exclusion
        combine.pop_back();
        getAllCombinations(arr,idx+1,tar,combine,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        getAllCombinations(candidates,0,target,combine,ans);
        return ans;   
    }
};