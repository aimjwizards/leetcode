/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> match;
        queue<UndirectedGraphNode*> visit;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        visit.push(node);
        match[node]=copy;
        while(!visit.empty()) {
            UndirectedGraphNode* curr = visit.front();
            visit.pop();
            for(auto n:curr->neighbors) {
                if(match.find(n)!=match.end()) {
                    match[curr]->neighbors.push_back(match[n]);
                }else{
                    UndirectedGraphNode* n_copy = new UndirectedGraphNode(n->label);
                    match[n] = n_copy;
                    match[curr]->neighbors.push_back(n_copy);
                    visit.push(n);
                }
            }
        }
        
        return copy;
    }
};
