class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mpp;
        queue<int> q;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mpp.find(s[i]) == mpp.end()){
                q.push(i);
            }
            mpp[s[i]]++;
            while(q.size() > 0 && mpp[s[q.front()]] > 1){
                q.pop();
            }
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
};