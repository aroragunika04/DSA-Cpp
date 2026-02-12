#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
        queue<int> q;
        queue<int> q2;
        
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size()>1){
            q2.push(q.front());
            q.pop();
        }
        int popped_el = q.front();
        q.pop();
        q.swap(q2);
        return popped_el;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};