#include<bits/stdc++.h>
using namespace std;
//1021: REMOVE OUTERMOST PARENTHESIS
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                //if stack is empty, it means we are at the start of an outermost parenthesis
                if(!st.empty()){
                    res+=s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                //if stack is empty, it means we have completed one outermost parenthesis
                if(!st.empty()){
                res +=s[i];
                }
            }
        }
        return res;

    }
};
