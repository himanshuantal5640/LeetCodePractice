class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum = 0;
        int ans = 0;
        mpp[0] = 1;
        for(int x:nums){
            sum += x;
            int rem = ((sum % k) + k)%k;
            ans += mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }
};