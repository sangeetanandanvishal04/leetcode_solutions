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
private:
    Node* f(Node* node, unordered_map<Node*, Node*>& vis){
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);
        vis[node] = clone;

        for(auto neigh: node->neighbors){
            if(vis.find(neigh) != vis.end()){
                neighbor.push_back(vis[neigh]);
            }
            else{
                neighbor.push_back(f(neigh, vis));
            }    
        }

        clone->neighbors = neighbor;
        return clone;
    }    
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> vis;
        return f(node, vis);
    }
};