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

    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr) {
            return node;
        }

        if(visited.count(node)) {
            return visited[node];
        }

        Node* cloneNode = new Node(node->val, vector<Node*>());
        visited[node] = cloneNode;

        for(Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;

    }
};