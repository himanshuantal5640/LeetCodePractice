class Solution {
public:
    int minimumK(vector<int>& nums) {
        int l = 0;
        int h = 1e6;
        int ans = h;
        while(l <= h){
            int mid = (l+h)/2;
            if(mid == 0){
                l = 1;
                continue;
            }
            long long op = 0;
            for(int x:nums){
                op += (x+mid - 1)/mid;
            }
            if(op <= (long long)mid*mid){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};