class Solution {
public:
    void solve(int idx,string digits,string curr,vector<string>& map,vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit = digits[idx] - '0';// current digit
        string letter = map[digit];
        for(char ch: letter){
            curr.push_back(ch);//choose
            solve(idx+1,digits,curr,map,ans);//explore next
            curr.pop_back();//backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        vector<string> map = {
            "",//0
            "",//1
            "abc",//2
            "def",//3
            "ghi",//4
            "jkl",//5
            "mno",//6
            "pqrs",//7
            "tuv",//8
            "wxyz"//9
        };
        solve(0,digits, "",map,ans);
        return ans;
    }
};