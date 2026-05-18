class Solution {
public:
    bool DFS(int src,vector<bool>& vis, vector<bool>& re,vector<vector<int>>& adj){
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
    void TopoOrder(int src, vector<bool>& vis,stack<int>& st,vector<vector<int>>& adj){
        vis[src] = true;
        vector<int> ne = adj[src];
        for(int v: ne){
            if(!vis[v]){
                TopoOrder(v,vis,st,adj);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto n:prerequisites){
            int u = n[0];
            int v = n[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> re(numCourses,false); //recursion stack to detect cycle
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(DFS(i,vis,re,adj)){
                    return ans;
                }
            }
        }
        stack<int> st;//Toplogical Sort
        vis.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                TopoOrder(i,vis,st,adj);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};