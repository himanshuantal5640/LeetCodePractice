class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> re(n);
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                int n1 = nums[i];
                int j = (i+n1)%n;
                re[i] = nums[j];
            }
            else if(nums[i] < 0){
                int n1 = abs(nums[i]);
                int j = (i - n1)%n;
                if(j < 0){
                    j += n;
                }
                re[i] = nums[j];
            }
            else if(nums[i] == 0){
                re[i] = nums[i];
            }
        }
        return re;
    }
};