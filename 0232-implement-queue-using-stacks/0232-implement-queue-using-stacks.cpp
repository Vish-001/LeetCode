class MyQueue {
public:
    stack<int>st;
    MyQueue() {}
    
    void push(int x) 
    {
        stack<int>st2;
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            st2.push(t);
        }
        st2.push(x);
        while(!st2.empty())
        {
            int t=st2.top();
            st2.pop();
            st.push(t);
        }
    }
    
    int pop() 
    {
        if(st.empty()) return -1;
        int t=st.top();
        st.pop();
        return t;
    }
    
    int peek() 
    {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */