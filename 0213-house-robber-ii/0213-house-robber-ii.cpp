class Solution {
public:
    int solve(vector<int> &nums,int s,int e){
        int p2 = 0;
        int p1 = 0;
        for(int i=s;i<=e;i++){
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
        int case1 = solve(nums,0,n-2);//include first and exclude last
        int case2 = solve(nums,1,n-1);//exclude first and include last;
        return max(case1,case2);
    }
};