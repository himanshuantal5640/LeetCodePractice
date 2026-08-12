class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi = 0;
        mpp[0] = -1;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            if(sum == 0){
                maxi = max(maxi,i+1);
            }
            if(mpp.find(sum) != mpp.end()){
                int len = i - mpp[sum];
                maxi = max(maxi,len);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxi;
    }
};