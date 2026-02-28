class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n,false);
        vector<int> minD(n,INT_MAX);
        minD[0] = 0;
        int re = 0;
        for(int i=0;i<n;i++){
            int u = -1;
            for(int j=0;j<n;j++){
                if(!vis[j] && (u == -1 || minD[j] < minD[u]) ){
                    u = j;
                }
            }
            vis[u] = true;
            re += minD[u];
            for(int v = 0;v<n;v++){
                if(!vis[v]){
                    int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minD[v] = min(minD[v],d);
                }
            }
        }
        return re;
    }
};