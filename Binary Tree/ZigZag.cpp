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
    //APPRAOCH:
    //Same as level order just keep a flag if it is true add level vector as it is and make it false for next level
    // if flag is false add reverse of level in ans vector and make flag truee for necct level
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            if(flag){
                ans.push_back(level);
                flag = false;
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                flag = true;
            }
            level.clear();
        }
        return ans;
    }
};