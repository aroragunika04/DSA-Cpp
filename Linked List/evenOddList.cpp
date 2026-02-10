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

 // Leetcode 328. Odd Even Linked List
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* newHead = even;
        
       while(odd->next && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
       }

        odd->next = newHead;
        return head;


    }
};