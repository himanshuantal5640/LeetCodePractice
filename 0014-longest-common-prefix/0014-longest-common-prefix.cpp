class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string f = strs[0];
        string l = strs[strs.size() - 1];
        int mini = min(f.size(),l.size());
        string ans = "";
        for(int i=0;i<mini;i++){
            if(f[i] != l[i]){
                break;
            }
            ans += f[i];
        }
        return ans;
    }
};