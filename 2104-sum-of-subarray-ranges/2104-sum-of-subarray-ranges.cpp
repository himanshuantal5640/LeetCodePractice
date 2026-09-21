class Solution {
public:

    long long sumMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> st;
        // Previous Smaller
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(st.empty())
                next[i] = n;
            else
                next[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans += 1LL * nums[i] * left * right;
        }
        return ans;
    }

    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> st;
        // Previous Greater
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }
        while(!st.empty())
            st.pop();
        // Next Greater
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if(st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans += 1LL * nums[i] * left * right;
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};