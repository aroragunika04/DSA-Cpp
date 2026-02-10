#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode 24. Swap Nodes in Pairs

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL || head->next == NULL){
        return head;
       }
       // we will use dummy node 
       ListNode* dummy = new ListNode(-1);
       dummy->next = head;
       ListNode* prev = dummy;

       //swap nodes in pair
       while(prev->next && prev->next->next){
        ListNode* f = prev->next;
        ListNode* s = prev->next->next;

        f->next = s->next;
        s->next = f;
        prev->next = s;
        
        // move prev to next pair
        prev = f;
       }    

       return dummy->next;
    }
};