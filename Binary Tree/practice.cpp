#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* create(Node *root){
    int val;
    cin>>val;

    if (val == -1) {
        return NULL;
    }
    root = new Node(val);
    
    root->left = create(root->left);
    root->right = create(root->right);
    

    return root;

}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root = NULL;
    root = create(root);

    preorder(root);
}