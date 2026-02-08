class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return 0;
        }
        int cnt = 0;
        long long sum = 0;
        int ETR = 0;
        for(int i=n-1;i>=0;i--){
            if(ETR > 0){
                if((long long)nums[i] * ETR > sum){
                    cnt++;
                }
            }
            sum += nums[i];
            ETR++;
        }
        return cnt;
    }
};