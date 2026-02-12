#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    // ~Node(){
    //     cout<<"Destructor called"<<endl;
    // }
};

class Stack{
    public:
    Node* head;
    int size;
    Stack(){
        head = nullptr;
        size = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);
        size++;
        if(head==NULL){
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;

        return ;
    }

    void pop(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top(){
        return head->data;
    }

    bool isEmpty(){
        return size==0;
    }
};

int main(){
    Stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.pop();
    cout<<st.top()<<endl;

    

}