class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& it : mp) {
            auto& arr = it.second;

            if (arr.size() < 3) {
                continue;
            }

            for (int i = 0; i + 2 < arr.size(); i++) {

                int dist = 2 * (arr[i + 2] - arr[i]);
                ans = min(dist, ans);
            }
        }
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
        return ans;
    }
};