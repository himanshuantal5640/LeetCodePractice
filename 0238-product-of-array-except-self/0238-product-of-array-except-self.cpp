//OPtimal solution  with SC=O(1) don,t store prefix or suffix as vector just directly use them them in ans without storing
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> re(n,1);
        //prefix
        for(int i=1;i<n;i++){
            re[i] = re[i-1] * nums[i-1];
        }
        //suffix 
        int suffix = 1;
        for(int i=n-2;i>=0;i--){
            suffix *= nums[i+1];
            re[i] *= suffix;
        }
        return re;
    }
};