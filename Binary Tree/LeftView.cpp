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

class Solution {
  public:
    //LEFT VIEW OF BINARY TREE
    //APPROACH 1:
    //LEVEL ORDER TRAVERSAL
    vector<int> leftView(Node *root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                //add the first node of every level in res vector
                if(i==0){
                    res.push_back(node->data);
                }
            }
        }
        return res;
        
    }
};
//APPROACH 2: USING RECURSION
class Solution {
  public:
    void solve(Node* root,vector<int> &res,int level){
        if(root==NULL){
            return;
        }
        if(level == res.size()){
            res.push_back(root->data);
        }
        solve(root->left,res,level+1);
        solve(root->right,res,level+1);
    }
    vector<int> leftView(Node *root) {
        vector<int> res;
        solve(root,res,0);
        return res;
        
    }
};