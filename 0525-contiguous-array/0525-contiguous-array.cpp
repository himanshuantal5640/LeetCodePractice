class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                sum++;
            }
            else{
                sum--;
            }
            if(sum == 0){
                maxi = max(maxi,i+1);
            }
            if(mp.find(sum) != mp.end()){
                int l = i - mp[sum];
                maxi = max(maxi,l);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxi;
    }
};