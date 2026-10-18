class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curMax = 0;
        int maxSum = 0;
        int curMin = 0;
        int minSum = 0;
        for(int x: nums){
            curMax = max(0,curMax+x);
            maxSum = max(maxSum,curMax);
            curMin = min(0,curMin+x);
            minSum = min(minSum,curMin);
        }
        return max(maxSum,-minSum);
    }
};