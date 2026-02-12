#include<bits/stdc++.h>
using namespace std;
//1381: Design Stack with increment Operation
//https://leetcode.com/problems/design-a-stack-with-increment-operation/
class CustomStack {
public:
    int size;
    vector<int> arr;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(size==arr.size()){
            return;
        }
        arr.push_back(x);
        //int n = arr.size()
    }
    
    int pop() {
        if(arr.empty()) return -1;
        int el = arr[arr.size()-1];
        arr.erase(arr.begin()+arr.size()-1);
        return el;
    }
    
    void increment(int k, int val) {
        if(k>arr.size()){
            k = arr.size();
        }
        for(int i=0;i<k;i++){
            arr[i] = arr[i]+val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */