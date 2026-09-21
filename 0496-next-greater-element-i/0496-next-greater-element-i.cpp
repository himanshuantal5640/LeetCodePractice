class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i = nums2.size() - 1;i>=0;i--){
            int x = nums2[i];
            while(!st.empty() && st.top() < x){
                st.pop();
            }
            if(st.empty()){
                mpp[x] = -1;
            }
            else{
                mpp[x] = st.top();
            }
            st.push(x);
        }
        for(int x:nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};