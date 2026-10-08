class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            int curr = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] >= curr){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans,h*w);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                }
                else{
                    h[j] = 0;
                }
            }
            ans = max(ans,largestRectangleArea(h));
        }
        return ans;
    }
};