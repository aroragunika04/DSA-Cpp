#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();         // Number of nodes at current level

            //process all nodes of curr level
            for(int i=0;i<size;i++){
                //take front of queue as node
            TreeNode* node = q.front();
                //delete it from queue
                q.pop();
                //add its children
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                // add node val to vector
                level.push_back(node->val);
            }
            ans.push_back(level);
            //clear vector to store nodes of next level
                level.clear();

        }
        return ans;
    }
};