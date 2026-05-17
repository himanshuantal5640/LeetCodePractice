class Solution {
public:
    bool DFS(int i,vector<int>& arr,vector<bool>& vis){
        if(i < 0 || i >= arr.size()){
            return false;
        }
        if(vis[i]){
            return false;
        }
        if(arr[i] == 0){
            return true;
        }
        vis[i] = true;
        return DFS(i+arr[i],arr,vis) || DFS(i - arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        return DFS(start,arr,vis);
    }
};