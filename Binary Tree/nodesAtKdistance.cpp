#include<bits/stdc++.h>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
//863. All Nodes Distance K in Binary Tree
//TC: O(N) SC: O(N)
//Approach : Use BFS and a map to store the parent of each node. Start BFS from the target node.
//keep track of the distance from the target node. When the distance is equal to k, add all the nodes at that distance to the answer vector.

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parents(TreeNode* root){
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left){
                    mp[front->left] = front;
                    q.push(front->left);
                }
                if(front->right){
                    mp[front->right] = front;
                    q.push(front->right);
                }
            }
        }

        return mp;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent = parents(root);
        vector<int> ans;
        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty()){
            int size = q.size();
            if(dist==k){
                break;
            }
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]= true;
                }
                if(parent.find(front)!=parent.end() && !visited[parent[front]]){
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};