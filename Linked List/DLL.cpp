#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node* head){
    Node* temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Insert at begin
Node* insert_begin(Node* head,Node* &tail,int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = tail = new_node;
        return head;
    }
    new_node->next  = head;
    head->prev = new_node;
    head = new_node;
    return head;
}

//Insert at last
Node* insert_end(Node* head,Node* &tail,int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = tail = new_node;
        return head;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    return head;
}
//Insert at position
Node* insert(Node* head,Node* &tail,int pos,int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    if(pos==1){
        head = insert_begin(head,tail,val);
        return head;
    }
    int cnt = 1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        head = insert_end(head,tail,val);
        return head;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    new_node->prev = temp;
    temp->next = new_node;
    return head;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    head = insert_begin(head,tail,10);
    head = insert_begin(head,tail,20);
    print(head);
    head = insert_end(head,tail,30);
    print(head);
    head = insert(head,tail,4,40);
    print(head);
    cout<<tail->data<<endl;
}
