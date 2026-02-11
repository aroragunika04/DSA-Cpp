#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Leetcode 86. Partition List
//Time complexity: O(n)
//Space complexity: O(1)
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL || head->next==NULL) return head;
        ListNode* head1 = new ListNode(-1);
        ListNode* head2 = new ListNode(-1);
        ListNode* lower = head1;
        ListNode* greater = head2;

        ListNode* curr = head;
        while(curr){
            if(curr->val<x){
                lower->next = curr;
                lower = lower->next;
            }
            else{
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }

        greater->next = NULL;
        lower->next = head2->next;

        return head1->next;
        
    }
};