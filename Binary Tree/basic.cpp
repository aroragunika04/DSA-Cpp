#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* create(Node* root){
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    root->left = create(root->left);
    root->right = create(root->right);
    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root = NULL;
    root = create(root);
    preorder(root);
}