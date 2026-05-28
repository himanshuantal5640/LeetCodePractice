// Hierholzer’s Algorithm  ==> “We use postorder DFS because in Eulerian Path we finalize a node only after all outgoing edges are exhausted.”
// Algorithm Flow

// Build graph:

// map<string, priority_queue<string>>

// (Min-heap → ensures lexical order)

// DFS:
// While current node has neighbors:
// Go to smallest neighbor
// Add node to result after visiting all edges
// Reverse the result
class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> ans;
    void DFS(string s){
        //visit all the padosi of current string
        while(!adj[s].empty()){
            string next = adj[s].top();
            adj[s].pop();
            DFS(next);
        }
        ans.push_back(s);//add airpot
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //build graph
        for(auto& it:tickets){
            adj[it[0]].push(it[1]);
        }
        DFS("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};