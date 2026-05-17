class Solution {
public:
    bool DFS(int src,vector<bool>& vis,vector<bool>& re,vector<vector<int>>& adj){
        vis[src] = true;
        re[src] = true;
        vector<int> ne = adj[src];
        for(int v : ne){
            if(!vis[v]){
                if(DFS(v,vis,re,adj)){
                    return true;
                }
            }
            else if(re[v]){
                return true;
            }
        }
        re[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto n:prerequisites){
            int u = n[0];
            int v = n[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> re(numCourses,false);//recursive for cycle detect
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(DFS(i,vis,re,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};