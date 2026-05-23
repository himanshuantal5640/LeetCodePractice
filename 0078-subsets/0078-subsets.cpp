class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& curr,vector<vector<int>>& re){
        if(idx == nums.size()){
            re.push_back(curr);
            return;
        }
        //include
        curr.push_back(nums[idx]);
        solve(idx+1,nums,curr,re);
        //exclude
        curr.pop_back();
        solve(idx+1,nums,curr,re);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> curr;
        solve(0,nums,curr,re);
        return re;
    }
};