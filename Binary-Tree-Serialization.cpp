/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        if(!root) return "#";
        return std::to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        if(data == "#") return nullptr;
        
        istringstream buf(data);
        istream_iterator<std::string> beg(buf), end;

        deque<string> tokens(beg, end);
        
        return deserialize(tokens);
    }
private:
    TreeNode *deserialize(deque<string>& tokens) {
        const string val = tokens.front(); tokens.pop_front();
        if(val == "#") return nullptr;
        TreeNode *node = new TreeNode(std::stoi(val));
        node->left = deserialize(tokens);
        node->right = deserialize(tokens);
        return node;
    }
};
