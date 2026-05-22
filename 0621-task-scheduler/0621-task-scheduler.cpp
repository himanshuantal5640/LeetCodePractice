class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int n1 = tasks.size();
        vector<int> freq(26,0);
        for(char ch:tasks){
            freq[ch - 'A']++;
        }
        int maxFreq = *max_element(freq.begin(),freq.end());
        int cntFreq = 0;
        for(int f:freq){
            if(f == maxFreq){
                cntFreq++;
            }
        }
        int ans = (maxFreq - 1) * (n + 1) + cntFreq;
        return max(n1,ans);
    }
};