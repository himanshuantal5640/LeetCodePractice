class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> store(mp.begin(),mp.end());
        sort(store.begin(),store.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second > b.second;
        });

        string ans = "";
        for(auto &it:store){
            for(int i=0;i<it.second;i++){
                ans += it.first;
            }
        }
        return ans;
    }
};