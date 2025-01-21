class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
        // Rotate the queue to simulate stack behavior
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop() {
        if (q.empty()) return -1; // Handle empty stack
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        if (q.empty()) return -1; // Handle empty stack
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
