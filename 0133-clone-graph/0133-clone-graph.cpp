class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;


        if (node->neighbors.empty()) return new Node(node->val);

        unordered_map<Node*, Node*> cp;
        queue<Node*> qu;

        cp[node] = new Node(node->val);
        qu.push(node);

        while (!qu.empty()) {

            Node* curr = qu.front();

            qu.pop();

            for (Node* nei : curr->neighbors) {

                if (cp.find(nei) == cp.end()) {

                    cp[nei] = new Node(nei->val);

                    qu.push(nei);
                }
                
                cp[curr]->neighbors.push_back(cp[nei]);
            }
        }
        return cp[node];
    }
};
