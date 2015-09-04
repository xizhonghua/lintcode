class MinStack {
public:
    MinStack() {
    }

    void push(int number) {
        s.push(number);
        if(m.empty() || number <= m.top())
            m.push(number);
    }

    int pop() {
        int val = s.top();
        s.pop();
        if(val==m.top()) m.pop();
        return val;
    }

    int min() {
        return m.top();
    }
private:
    stack<int> s;
    stack<int> m;
};
