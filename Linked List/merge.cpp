#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* insert(Node* head,int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}
Node* merge(Node* head1,Node* head2){
    Node* head = new Node(-1); //make a dummy node in new list
    Node* temp = head;
    while (head1!=NULL && head2!=NULL)        //same logic as merge sort
    {
        if(head1->data<head2->data){
            temp->next = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    while(head1){
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
    while(head2){
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    return head->next;    //skips the dummy node(-1)
    
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int val;
    for(int i=0;i<5;i++){
        cin>>val;
        head1 = insert(head1,val);
    }
    for(int i=0;i<4;i++){
        cin>>val;
        head2 = insert(head2,val);
    }
    Node* head= nullptr;
    head = merge(head1,head2);
    print(head);

    
}