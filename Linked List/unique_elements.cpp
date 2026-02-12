#include<bits/stdc++.h>
using namespace std;

//82. Remove Duplicates from Sorted List II

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* delete_duplicates(Node* head){
    Node* curr = head;
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* ans = new Node(-1); //dummy node
    Node* temp = ans;
    while(curr && curr->next){
        if(curr->data == curr->next->data){
            while(curr->next && curr->data== curr->next->data){
                curr = curr->next;
            }
            curr = curr->next;
        }
        else{
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
        }
    }
    temp->next = curr;
    head = ans->next;
    return head;
}