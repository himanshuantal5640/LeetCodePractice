class Solution {
public:
    void PS(vector<int>& nums,vector<vector<int>> &All,vector<int> &ans,int i){
        if(i == nums.size()){
            All.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        //include
        PS(nums,All,ans,i+1);
        ans.pop_back();//backtrack
        //Exclude
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        PS(nums,All,ans,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> All;
        vector<int> re;   
        PS(nums,All,re,0);
        return All;
    }
};