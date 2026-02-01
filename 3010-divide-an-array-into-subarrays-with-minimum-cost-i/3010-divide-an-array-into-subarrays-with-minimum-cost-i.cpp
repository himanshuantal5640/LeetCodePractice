class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int re = nums[0];
        sort(nums.begin()+1,nums.end());
        re += nums[1]+nums[2];
        return re;

    }
};