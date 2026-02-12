#include<bits/stdc++.h>
using namespace std;
 //234.PALINDROME LIST
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      queue<int> q;
      stack<int> st;
      ListNode* temp = head;
      while(temp){
        q.push(temp->val);
        st.push(temp->val);
        temp = temp->next;
      }
      while(!q.empty() && !st.empty()){
        if(q.front()!=st.top()){
            return false;
        }
        q.pop();st.pop();
      }

        return true;

    }
};