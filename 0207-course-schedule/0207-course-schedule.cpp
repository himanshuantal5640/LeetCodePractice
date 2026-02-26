class Solution {
public:
    bool dfs(int src,vector<bool> &vis,vector<bool> &re,vector<vector<int>>& adj){
        vis[src] = true;
        re[src] = true;
        vector<int> ne = adj[src];
        for(int v:ne){
            if(!vis[v]){
                if(dfs(v,vis,re,adj)){
                    return true;
                }
            }
            else if(re[v]){ //Back Edge
                return true;
            }
        }
        re[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto ne : prerequisites){
            int u = ne[0];
            int v = ne[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> re(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,re,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};