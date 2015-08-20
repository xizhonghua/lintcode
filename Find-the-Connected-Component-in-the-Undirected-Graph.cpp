/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        set<UndirectedGraphNode*> visited;
        vector<vector<int>> ans;
        for(const auto n : nodes) {
            set<UndirectedGraphNode*> current;
            if(!visited.count(n)) {
                findConnectedSet(n, 1, visited, current, ans);
                vector<int> sub_graph;
                for(const auto n : current)
                    sub_graph.push_back(n->label);
                std::sort(sub_graph.begin(), sub_graph.end());
                ans.push_back(sub_graph);
            }
            
        }
        return ans;
    }
    
private:
    void findConnectedSet(UndirectedGraphNode* node, 
                          int depth,
                          set<UndirectedGraphNode*>& visited,
                          set<UndirectedGraphNode*>& current,
                          vector<vector<int>>& ans) {
        visited.insert(node);
        current.insert(node);
        
        for(const auto neighbor : node->neighbors) {
            if(!visited.count(neighbor)) {
                findConnectedSet(neighbor, depth+1, visited, current, ans);
            }
        }
    }
};
