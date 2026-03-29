// calculate all possible rectangle and their areas and then return ans 
// TC = O(n^2)

// For Optimal approach use stack and calculatr left neart smalleer and right nearst smaller for every index 
// TC = O(n).
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        stack<int> st;
        //right smaller
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // left smaller
        for(int i=0;i<n;i++){
            while(st.size() >0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        int area = 0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int curr = heights[i]*width;
            area = max(area,curr);
        }
        return area;
    }
};