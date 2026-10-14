class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long sum = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            mpp[nums[i]]++;
            if(i >= k){
                sum -=nums[i - k];
                mpp[nums[i - k]]--;
                if(mpp[nums[i - k]] == 0){
                    mpp.erase(nums[i - k]);
                }
            }
            if(i >= k-1 && mpp.size() == k){
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};