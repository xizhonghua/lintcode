class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for(const auto& token : tokens) {
            if(token[0]>='0' && token[0]<='9' || (token[0]=='-' && token.size()>1)) 
                operands.push(std::stoi(token));
            else {
                int op2 = operands.top(); operands.pop();
                int op1 = operands.top(); operands.pop();
                int result = 0;
                if (token == "+") 
                    result = op1 + op2;
                else if(token == "-")
                    result = op1 - op2;
                else if(token == "*")
                    result = op1 * op2;
                else if(token == "/")
                    result = op1 / op2;
                operands.push(result);
            }
        }
        return operands.top();
    }
};
