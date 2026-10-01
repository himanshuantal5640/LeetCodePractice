class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};