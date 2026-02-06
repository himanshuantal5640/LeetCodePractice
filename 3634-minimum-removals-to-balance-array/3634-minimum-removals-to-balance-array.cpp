class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            while(nums[i] > 1LL * k * nums[l]){
                l++;
            }
            maxi = max(maxi,i-l+1);
        }
        return n - maxi;
    }
};