class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;//size,vector
        vector<vector<int>> re;
        for(int i=0;i<n;i++){
            int s = groupSizes[i];
            mp[s].push_back(i);
            if(mp[s].size() == s){
                re.push_back(mp[s]);
                mp[s].clear();
            }
        }
        return re;
    }
};