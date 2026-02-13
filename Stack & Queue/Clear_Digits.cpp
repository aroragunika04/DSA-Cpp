#include<bits/stdc++.h>
using namespace std;

// 3174. Clear Digits
//https://leetcode.com/problems/clear-digits/
// input = a3bc; bc34
//output = bc;  ""
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string res;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i]) && !st.empty()){
                st.pop();
            }
            else{
            st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};