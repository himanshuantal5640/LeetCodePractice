class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Min-heap -> {cost, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0, 0});
        int cost = 0;
        int edges = 0;
        while(edges < n) {
            auto [wt, node] = pq.top();
            pq.pop();
            // Skip if already visited
            if(vis[node])
                continue;
            vis[node] = true;
            cost += wt;
            edges++;
            // Add all neighbors
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    int dist =
                    abs(points[node][0] - points[j][0]) +
                    abs(points[node][1] - points[j][1]);
                    pq.push({dist, j});
                }
            }
        }
        return cost;
    }
};