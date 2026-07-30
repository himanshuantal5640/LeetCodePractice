class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        //sort in lexilogical order
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        int mini = min(first.size(),last.size());
        string ans = "";
        for(int i=0;i<mini;i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};