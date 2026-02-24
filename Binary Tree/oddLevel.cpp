
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
    vector<int> nodesAtOddLevels(Node *root) {
        queue<Node*> q;
        vector<int> res;
        bool odd = true;
        //int level = 1;
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
                //if(level%2!=0){
                // res.push_back(node->data)
                // }
                if(odd){
                    res.push_back(node->data);
                }
            }
            //instead of this u can also count levels;
            //level++;
            if(odd){
            odd = false;
            }
            else{
                odd = true;
            }
        }
        return res;
        
    }
};