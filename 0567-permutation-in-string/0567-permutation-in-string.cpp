// first store the frequency of character in s1
// search s1 permutation in s2 use window based searching similar to sliding window
class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int windSize = s1.size();
        for(int i=0;i<s2.size();i++){
            int windIdx = 0;
            int idx = i;
            int windFreq[26] = {0};
            while(windIdx < windSize && idx < s2.size()){
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }
            if(isFreqSame(freq,windFreq)){
                return true;
            }
        }
        return false;
    }
};