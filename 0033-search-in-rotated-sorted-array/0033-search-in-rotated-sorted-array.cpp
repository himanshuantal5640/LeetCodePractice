class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int r = nums.size() - 1;
        while(s <= r){
            int m = (s+r)/2;
            if(nums[m] == target){
                return m;
            }
            if(nums[s] <= nums[m]){
                if(nums[s] <= target && target <= nums[m]){
                    r = m - 1;
                }
                else{
                    s = m + 1;
                }
            }
            else{
                if(target <= nums[r] && nums[m] <= target){
                    s = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};