class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,int n,int k) {     
        // Adjacency list
        vector<pair<int,int>> adj[n + 1];
        for(auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2]; 
            adj[u].push_back({v, w});
        } 
        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        // Min heap -> {distance, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;        
       // Source node
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) { 
            auto it = pq.top();
            pq.pop();          
            int d = it.first;
            int node = it.second;            
            // Explore neighbors
            for(auto &nbr : adj[node]) {               
                int nextNode = nbr.first;
                int weight = nbr.second;          
                // Relaxation
                if(d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;           
                    pq.push({dist[nextNode], nextNode});
                }
            }
        } 
        // Find maximum shortest distance
        int ans = 0;
        for(int i = 1; i <= n; i++) { 
            // Unreachable node
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};