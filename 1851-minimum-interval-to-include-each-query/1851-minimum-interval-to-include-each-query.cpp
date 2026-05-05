class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        
        // Step 1: sort intervals by start
        sort(intervals.begin(), intervals.end());
        
        // Step 2: store queries with index
        vector<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        
        // Min heap: {size, right}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> ans(n, -1);
        int i = 0;
        
        // Step 3: process queries
        for(auto &[query, idx] : q) {
            
            // Add all intervals with left <= query
            while(i < intervals.size() && intervals[i][0] <= query) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }
            
            // Remove invalid intervals (right < query)
            while(!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            // Top of heap = smallest valid interval
            if(!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }
        
        return ans;
    }
};