class Solution {
public:
    void solve(int i,string& arr,vector<string>& map,string& path,vector<string>& ans){
        if(i == arr.size()){
            ans.push_back(path);
            return;
        }
        int digit = arr[i] - '0';
        string letter = map[digit];
        for(char ch:letter){
            path.push_back(ch);
            solve(i+1,arr,map,path,ans);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> ans;
        string path;
        vector<string> map{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        solve(0,digits,map,path,ans);
        return ans;
        
    }
};