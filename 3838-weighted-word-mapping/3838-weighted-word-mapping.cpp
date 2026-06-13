class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string &word: words){
            long long sum = 0;
            for(char c: word){
                sum += weights[c - 'a'];
            }
            int val = sum%26;
            char mapped = 'z' - val;
            ans.push_back(mapped);
        }
        return ans;
    }
};