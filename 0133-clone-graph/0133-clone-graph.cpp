/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,unordered_map<Node*,Node*>& mp){
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto &ne : node->neighbors){
            if(mp.find(ne) == mp.end()){
                newNode->neighbors.push_back(solve(ne,mp));
            }
            else{
                newNode->neighbors.push_back(mp[ne]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        unordered_map<Node*,Node*> mp; //{org,copy}
        return solve(node,mp);
    }
};