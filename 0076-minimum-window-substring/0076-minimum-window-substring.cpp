class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n){
            return "";
        }
        vector<int> freq(256);
        for(char ch:t){
            freq[ch]++;
        }
        int start = 0;
        int cnt = m;
        int left = 0;
        int mini = INT_MAX;
        for(int right = 0;right < n;right++){
            char ch = s[right];
            if(freq[ch] > 0){
                cnt--;
            }
            freq[ch]--;
            while(cnt == 0){
                if(right - left + 1 < mini){
                    mini = right - left + 1;
                    start = left;
                }
                char ch = s[left];
                freq[ch]++;
                if(freq[ch] > 0){
                    cnt++;
                }
                left++;
            }
        }
        if(mini == INT_MAX){
            return "";
        }
        return s.substr(start,mini);
    }
};