class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto n:flights){
            int u = n[0];
            int v = n[1];
            int w = n[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<int,int>> q;
        q.push({src,0});
        int stop = 0;
        while(!q.empty() && stop <= k){
            int s = q.size();
            vector<int> temp = dist;
            while(s--){
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                for(auto ne: adj[node]){
                    int next = ne.first;
                    int price = ne.second;
                    if(cost + price < temp[next]){
                        temp[next] = cost + price;
                        q.push({next,temp[next]});
                    }
                }
            }
            dist = temp;
            stop++;
        }
        return dist[dst] == INT_MAX ? -1: dist[dst];
    }
};