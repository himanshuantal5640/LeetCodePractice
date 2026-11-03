
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if (n < totalLen){
            return ans;
        }
        unordered_map<string, int> wordMap;
        for (string word : words) {
            wordMap[word]++;
        }
        // Try every possible starting offset
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;
            for (int right = i; right + wordLen <= n;right += wordLen) {
                string word = s.substr(right, wordLen);
                // Word is not required
                if (wordMap.find(word) == wordMap.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                seen[word]++;
                count++;
                // Frequency exceeds required frequency
                while (seen[word] > wordMap[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
                // All words matched
                if (count == wordCount) {
                    ans.push_back(left);
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }
        return ans;
    }
};
