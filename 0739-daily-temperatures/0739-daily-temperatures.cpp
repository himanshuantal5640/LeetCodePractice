class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> st; // store index;
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int p = st.top();
                st.pop();
                ans[p] = i-p;
            }
            st.push(i);
        }
        return ans;
    }
};