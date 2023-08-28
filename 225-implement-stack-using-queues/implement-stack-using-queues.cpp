class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
     this->size=0;
    }
    
    void push(int x) {
     int l=this->size;
     q.push(x);
     while( l !=0){
        q.push(q.front());
        q.pop();
        l--;
     }
     this->size++;
    }
    
    int pop() {
     int top=q.front();
     q.pop();
     this->size--;
     return top;
    }
    
    int top() {
     return q.front();
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