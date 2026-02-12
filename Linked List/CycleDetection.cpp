#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//FLOYD'S CYCLE DETECTION ALGO
//time complexity: O(n)
struct Node {
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Solution {
  public:   
    //Function to check if the linked list has a loop.
    bool hasCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;          //move slow by 1
            fast = fast->next->next;   //move fast by 2
            if(slow==fast){             //if both meet then cycle is present
                return true;
            }
        }
        return false;                  //if loop ends then no cycle is present
    }
    
    //Function to find the starting point of the loop.
    Node* findLoopStart(Node *head) {  
        Node* slow = head;
        Node* fast = head;
        bool cycle = false;
        
        //first check if cycle is present
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                cycle = true;  //cycle is present
                break;
            }
        }
        
        if(!cycle) return NULL; //if no cycle then return NULL
        
        //find the starting point of the loop
        slow = head; //reset slow to head
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow; //return the starting point of the loop
    }
};