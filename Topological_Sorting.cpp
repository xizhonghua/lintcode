/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    typedef DirectedGraphNode NODE;
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        set<NODE*> v;
        stack<NODE*> s;
        
        for(auto n : graph)
            if(!v.count(n))
                dfs(n, v, s);
            
        vector<NODE*> ans;
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    
private:
    void dfs(NODE* node, set<NODE*>& visited, stack<NODE*>& s)
    {
        visited.insert(node);
        for(auto n : node->neighbors)
            if(!visited.count(n))
                dfs(n, visited, s);
                
        s.push(node);
    }
};
