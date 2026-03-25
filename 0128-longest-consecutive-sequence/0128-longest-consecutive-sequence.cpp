class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = 0;
        for(int s:st){
            if(st.find(s - 1) == st.end()){
                int curr = s;
                int cnt = 1;
                while(st.find(curr+1) != st.end()){
                    curr++;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }  
        return maxi;
    }
};