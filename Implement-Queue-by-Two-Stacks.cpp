class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        if(stack2.empty()) swap();
        int e = stack2.top();
        stack2.pop();
        return e;
    }

    int top() {
        if(stack2.empty()) swap();
        return stack2.top();
    }
private:
    void swap() {
        while(!stack1.empty()) {
            auto e = stack1.top();
            stack2.push(e);
            stack1.pop();
        }
    }
};
