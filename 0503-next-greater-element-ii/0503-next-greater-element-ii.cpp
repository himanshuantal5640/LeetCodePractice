class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i = 2*n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<= nums[i%n]){
                s.pop();
            }
            ans[i%n] = !s.empty()? nums[s.top()]:-1;
            s.push(i%n);
        }
        return ans;
    }
};