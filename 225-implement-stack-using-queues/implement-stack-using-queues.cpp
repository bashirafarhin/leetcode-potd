class MyStack {
    queue<int> q1;
    queue<int> q2;
    int size;
public:
    MyStack() {
     this->size=0;
    }
    
    void push(int x) {
     while(!q1.empty()){
         q2.push(q1.front());
         q1.pop();
     }
     q1.push(x);
     while(!q2.empty()){
         q1.push(q2.front());
         q2.pop();
     }
     this->size++;
    }
    
    int pop() {
     int top=q1.front();
     q1.pop();
     this->size--;
     return top;
    }
    
    int top() {
     return q1.front();
    }
    
    bool empty() {
     if(this->size==0){return true;}
     return false;
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