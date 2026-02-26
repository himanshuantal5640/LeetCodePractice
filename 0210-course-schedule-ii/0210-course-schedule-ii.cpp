class Solution {
public:
    bool isCycle(int src,vector<bool>& vis,vector<bool>& re,vector<vector<int>>& adj){
        vis[src] = true;
        re[src] = true;
        vector<int> ne = adj[src];
        for(int v:ne){
            if(!vis[v]){
                if(isCycle(v,vis,re,adj)){
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
    void topo(int src,vector<bool>& vis,stack<int> &st,vector<vector<int>>& adj){
        vis[src] = true;
        vector<int> ne = adj[src];
        for(int v:ne){
            if(!vis[v]){
                topo(v,vis,st,adj);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto n:prerequisites){
            int u = n[1];
            int v = n[0];
            adj[u].push_back(v);
        }
        vector<int> ans;
        vector<bool> vis(numCourses,false);
        vector<bool> re(numCourses,false);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,vis,re,adj)){
                    return ans;
                }
            }
        }
        // No cycle use topological sort

        vis.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topo(i,vis,st,adj);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};