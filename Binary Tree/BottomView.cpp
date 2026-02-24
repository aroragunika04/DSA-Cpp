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
    vector<int> bottomView(Node *root) {
        vector<int> res;
        queue<pair<int,Node*>> q;
        map<int,int> mp;
        //check if root is null
        if(root==NULL){
            return res;
        }
        //add root and line no 0
        q.push({0,root});
        
        while(!q.empty()){
            auto it = q.front();
            int line = it.first;
            Node* node = it.second;
            
            //update value for line no
            mp[it.first] = node->data;
            
            q.pop();
            
            //add left nd right child of curr node
            if(node->left){
                q.push({line-1,node->left});
            }
            if(node->right){
                q.push({line+1,node->right});
            }
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};