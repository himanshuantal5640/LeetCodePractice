// first store the frequency of character in s1
// search s1 permutation in s2 use window based searching similar to sliding window
class Solution {
public:
    bool isSame(int a[],int b[]){
        for(int i = 0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int f[26] = {0};
        for(int i = 0;i<s1.size();i++){
            f[s1[i] - 'a']++;
        }
        int windSize = s1.size();
        for(int i=0;i<s2.size();i++){
            int windIdx = 0;
            int idx = i;
            int wf[26] = {0};
            while(windIdx < windSize && idx < s2.size()){
                wf[s2[idx] - 'a']++;
                idx++;
                windIdx++;
            }
            if(isSame(f,wf)){
                return true;
            }
        }
        return false;
    }
};