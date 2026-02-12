#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Leetcode 496. Next Greater Element I
//Time complexity: O(n)
//Space complexity: O(n)

//Approach : Use stack to store the elements of nums2 and a vector to store the next greater element for each element in nums2.
// Loop through nums2 from right to left and for each element, pop the elements from the stack until we find a greater element or the stack becomes empty.
// If we find a greater element, store it in the vector. If the stack becomes empty,store -1 in the vector.


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> greater(nums2.size(),-1);
    stack<int> st;
    unordered_map<int,int> mp;
    vector<int> res;
        
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(!st.empty()){
            greater[i] = st.top();
        }
        st.push(nums2[i]);
    }
        
    //use a map to store the next greater element for each element in nums2
    for(int i=0;i<nums2.size();i++){
        mp[nums2[i]] = greater[i];
    }


    for(int i : nums1){
        if(mp.find(i)!=mp.end()){
            res.push_back(mp[i]);
        }
    }
    return res;
}
