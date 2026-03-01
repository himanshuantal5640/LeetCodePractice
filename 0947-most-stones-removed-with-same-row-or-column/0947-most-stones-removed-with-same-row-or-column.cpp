class Solution {
public:
    void dfs(int src,vector<bool> &vis,vector<vector<int>> &adj){
        vis[src] = true;
        vector<int> ne = adj[src];
        for(int v:ne){
            if(!vis[v]){
                dfs(v,vis,adj);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int c = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                c++;
            }
        }
        return n - c;
    }
};