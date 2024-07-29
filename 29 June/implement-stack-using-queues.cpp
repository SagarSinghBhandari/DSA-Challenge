class MyStack {
    queue<int> qu;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        qu.push(x);
        for(int i=1; i<qu.size(); i++){
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop(){
        int k = top();
        qu.pop();
        return k;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
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