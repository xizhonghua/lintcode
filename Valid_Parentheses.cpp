class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> p;
        map<char, char> m = {{'}','{'}, {']', '['}, {')','('}};
        
        for(const char c : s) {
            if(m.count(c)) {
                if (p.empty() || p.top() != m[c]) return false;
                p.pop();
            }
            else
                p.push(c);
        }
        
        return p.empty();
    }
};
