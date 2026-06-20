class MyQueue {
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {
        
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        peek();  // Ensure outStack has elements

        int value = outStack.top();
        outStack.pop();

        return value;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
