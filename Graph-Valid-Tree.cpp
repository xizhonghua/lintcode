class Solution {
public:
    typedef unordered_map<int, vector<int>> G;
    
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        G g;
        unordered_set<int> v;
        
        for(const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        if(!visit(g, -1, 0, v)) return false;
        
        return n==1 ? v.size()==0 : v.size() == n;
    }
    
    bool visit(const G& g, int p, int node, unordered_set<int>& v) {
        if(v.count(node)) return false;
        if(!g.count(node)) return true;
        
        v.insert(node);
        
        for(const auto t : g.at(node))
        {
            if(t == p) continue;
            if(!visit(g, node, t, v)) return false;
        }
        
        return true;
    }
};
