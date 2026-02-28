class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto n:edges){
            int u = n[0];
            int v = n[1];
            int w = n[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int city = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }

};