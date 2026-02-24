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

//Largest value in each level
class Solution {
  public:
    vector<int> largestValues(Node* root) {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            //take el 
            int el=0;
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                //at each level update el with max element at a specific level
                el = max(el,node->data);
            }
            res.push_back(el);
            
        }
        return res;
        
    }
};