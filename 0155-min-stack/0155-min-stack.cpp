class MinStack {
public:
    stack<int> st;        // Main stack
    stack<int> minStack;  // Auxiliary stack to track minimum values

    MinStack() {}

    void push(int val) {
        st.push(val);
        // Push the minimum value so far onto the minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (st.top() == minStack.top()) {
            minStack.pop(); // Remove the corresponding minimum
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.top(); // The top of minStack is the current minimum
    }
};
