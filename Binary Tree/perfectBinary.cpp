#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    bool isPerfect(Node *root){
        queue<Node*> q;
        if(root==NULL){
            return true;
        }
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(size!=pow(2,level)){
                return false;
            }
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
        
    }
        
    
};