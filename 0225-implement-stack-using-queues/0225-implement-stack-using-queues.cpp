class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        int top_element = q1.front();
        q1.pop();

        swap(q1, q2);

        return top_element;
    }
    
    int top() {
        while(q1.size() > 1){
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        int top_element = q1.front();
        q1.pop();
        q2.push(top_element);

        swap(q1, q2);

        return top_element;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */