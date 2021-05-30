class MyStack {
public:
    queue<int> p;

    MyStack() {
    }
    
    void push(int x) {
        p.push(x);
    }
    
    int pop() {
        for(auto i=0; i<p.size()-1; i++)
        {
            p.push(p.front());
            p.pop();
        }
        int val = p.front();
        p.pop();
        return val;
    }
    
    int top() {
        return p.back();
    }
    
    bool empty() {        
        return !p.size();
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