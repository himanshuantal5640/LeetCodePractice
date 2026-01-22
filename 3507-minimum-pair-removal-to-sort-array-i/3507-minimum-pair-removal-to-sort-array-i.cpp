class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        
        while(true) {
            bool sorted = true;
            int n = nums.size();
            
            int minSum = nums[0] + nums[1];
            int idx = 0;
            
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[i-1]) sorted = false;
                if(i < n-1) {
                    int s = nums[i] + nums[i+1];
                    if(s < minSum) {
                        minSum = s;
                        idx = i;
                    }
                }
            }
            
            if(sorted) break;
            
            nums[idx] += nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }      
        return ops;
    }
};