class Solution {
public:
    int solve(vector<int> &nums,int s,int e){
        int p2 = 0;
        int p1 = 0;
        for(int i = s;i<=e;i++){
            int t = nums[i] + p2;
            int s = p1;
            int c = max(t,s);
            p2 = p1;
            p1 = c;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int c1 = solve(nums,0,n-2);
        int c2 = solve(nums,1,n-1);
        return max(c1,c2);
    }
};