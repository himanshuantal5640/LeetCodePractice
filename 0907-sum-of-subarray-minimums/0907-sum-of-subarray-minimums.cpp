class Solution {
public:
    long long m = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n);
        vector<int> next(n);
        for(int i=0;i<n;i++){
            int x = arr[i];
            while(!st.empty() && arr[st.top()] >= x){
                st.pop();
            }
            if(st.empty()){
                prev[i] = -1;
            }
            else{
                prev[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1;i>=0;i--){
            int x = arr[i];
            while(!st.empty() && arr[st.top()] > x){
                st.pop();
            }
            if(st.empty()){
                next[i] = n;
            }
            else{
                next[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contribution = (arr[i]*left)%m * right % m;
            ans = (ans + contribution)%m;
        }
        return (int)ans;
    }
};