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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int,int> mp;
        vector<int> res;
        if(root==NULL){
            return res;
        }
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            int size = q.size();
            auto it = q.front();
            
            int line = it.first;
            Node* node = it.second;
            q.pop();
            
            //if line not found in map add line and curr node data
            if(mp.find(it.first)==mp.end()){
                mp[it.first] = node->data;
            }
            //for left child line is line-1
            if(node->left){
                q.push({line-1,node->left});
            }
            //for right child line is line+1
            if(node->right){
                q.push({line+1,node->right});
            }
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};