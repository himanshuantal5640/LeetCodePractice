class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int s = nums.size();
        int can1;
        int can2;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int n : nums){
            if(n == can1){
                cnt1++;
            }
            else if(n == can2){
                cnt2++;
            }
            else if(cnt1 == 0){
                can1 = n;
                cnt1++;
            }
            else if(cnt2 == 0){
                can2 = n;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //verify element
        cnt1 = 0;
        cnt2 = 0;
        for(int n:nums){
            if(n == can1){
                cnt1++;
            }
            else if(n == can2){
                cnt2++;
            }
        }

        vector<int> ans;
        if(cnt1 > s/3 ){
            ans.push_back(can1);
        }
        if(cnt2 > s/3){
            ans.push_back(can2);
        }
        return ans;
    }
};