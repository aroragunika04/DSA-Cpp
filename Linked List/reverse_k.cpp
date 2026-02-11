#include <bits/stdc++.h>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 //Leetcode 25. Reverse Nodes in k-Group
//Time complexity: O(n)
//Space complexity: O(1)

//Approach: We will reverse the first k nodes of the linked list and then recursively call the function for the next k nodes.
//We will also check if there are at least k nodes left in the linked list before making the recursive call. 
//If there are less than k nodes left, we will not reverse them and just connect the last node of the reversed part 
//to the remaining nodes.

class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* curr  = head;

        int cnt = 0;
        while(cnt<k && curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }

        ListNode* count = curr;
        int length = 0;
        while(count){
            length++;
            count= count->next;
        }
        if(curr){
            if(length>=k){
            head->next = reverseKGroup(curr,k);
            }
            else{
                head->next = curr;
            }
        }

        return prev;
    }
};