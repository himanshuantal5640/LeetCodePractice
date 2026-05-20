class Solution {
public:
    int findParent(int x, vector<int>& parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findParent(parent[x],parent);//path Compression
    }
    bool Union(int u,int v, vector<int>& parent){
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
        if(pu == pv){
            return false;//cycle found
        }
        parent[pu] = pv;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(!Union(u,v,parent)){
                return it;
            }
        }
        return {};
    }
};