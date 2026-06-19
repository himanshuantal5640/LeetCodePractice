class Solution {
public:
    int solve(int start,int end,vector<int>& nums){
        int p2 = 0;
        int p1 = 0;
        for(int i=start;i<=end;i++){
            int take = nums[i] + p2;
            int skip = p1;
            int curr = max(take,skip);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int include = solve(0,n-2,nums);
        int exclude = solve(1,n-1,nums);
        return max(include,exclude);
    }
};