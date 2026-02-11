#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//Leetcode 61. Rotate List
//Time complexity: O(n)

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    int count(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
        return head;
        }
        int size = count(head);
        k = k % size;
        if(k==0){
        return head;
        }
        head = reverse(head);                                  //Reverse whole list

        ListNode* temp = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        int cnt = 0;
        
        while(cnt<k && curr){                                  //Reverse first k nodes
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        }

        if(curr){
        head->next = reverse(curr);                            //Reverse rest and connect to head->next;
        }

        return prev;
    }

};
