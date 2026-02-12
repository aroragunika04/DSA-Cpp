#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(),-1);
        
        for(int i=0;i<arr.size();i++){                  //for left loop from n-1 to 0
            while(!st.empty() && st.top()>=arr[i]){        //for right loop from 0 to n-1
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};