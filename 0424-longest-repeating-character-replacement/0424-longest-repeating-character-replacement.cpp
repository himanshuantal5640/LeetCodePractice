class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int left = 0;
        int maxi = 0;
        int ans = 0;
        for(int right = 0;right < n ;right++){
            mpp[s[right]]++;
            maxi = max(maxi,mpp[s[right]]);
            int windowSize = right - left + 1;
            if(windowSize - maxi > k){
                mpp[s[left]]--;
                left++;
            }
            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};