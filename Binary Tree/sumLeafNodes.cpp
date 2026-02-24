#include<bits/stdc++.h>
using namespace std;
 struct Node
 {
     int data;
     Node* left, *right;
}; 

//
class Solution {
  public:
    void solve(Node* root,int &sum,int num){
        if(root==NULL){
            return;
        }
        num = num*10+root->data;
        if(root->left==NULL && root->right==NULL){
            sum+=num;
            return;
        }
        solve(root->left,sum,num);
        solve(root->right,sum,num);
        
    }
    
    int treePathsSum(Node *root) {
        
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};