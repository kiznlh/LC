#include <bits/stdc++.h>
using namespace std;

class MyQueue {
stack<int> Queue;
public:
    MyQueue() {
        
    }
    void push(int x) {
        stack<int> temp; 
        while(!Queue.empty()){
            temp.push(Queue.top());
            Queue.pop();
        }
        Queue.push(x);
        while(!temp.empty()){
            Queue.push(temp.top());
            temp.pop();
        }
       
    }
    
    int pop() {
        int temp = Queue.top();
        Queue.pop();
        return temp;
    }
    
    int peek() {
        return Queue.top();
    }
    
    bool empty() {
        return Queue.empty();
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