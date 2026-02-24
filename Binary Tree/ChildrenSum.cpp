#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. 
//Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. 
class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if(root==NULL){
            return 1;
        }
        if(!root->left && !root->right){
            return 1;
        }
         
        int left = (root->left) ? root->left->data:0;
        int right = (root->right) ? root->right->data:0;
        
        return (root->data== left+right) && isSumProperty(root->left) && isSumProperty(root->right);
        
    }
};