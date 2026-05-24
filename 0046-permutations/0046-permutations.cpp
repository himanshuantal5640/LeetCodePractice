class Solution {
public:
    void solve(vector<int>& nums,vector<int>& cur,vector<vector<int>>& ans,vector<bool>& used){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i] = true;//choose
            cur.push_back(nums[i]);
            solve(nums,cur,ans,used);//explore
            cur.pop_back();//backtrack
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(),false);
        solve(nums,cur,ans,used);
        return ans;
    }
};