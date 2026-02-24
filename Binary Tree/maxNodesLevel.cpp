#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Return the level (0-indexed) with maximum number of nodes.
    int maxNodeLevel(Node *root) {
        int level = 0;
        queue<Node*> q;
        q.push(root);
        int maxSize = 0;
        int ans=0;
        while(!q.empty()){
            //n gives count of nodes
            int n = q.size();
            //if max is less than curr count update with count
            //update the level also
            if(maxSize<n){
                maxSize = n;
                ans = level;
            }
            for(int i=0;i<n;i++){
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
        return ans;
    }
};