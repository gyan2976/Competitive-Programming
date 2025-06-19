#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype> 
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Brute Force - O(n)
// Using Stack
string reverseWords(string s)
{
    stack<string> st;
    string str = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') 
        {
            if(!str.empty()) 
            {  // Only push non-empty strings
                st.push(str);
                str = "";
            }
        } 
        else 
        {
            str += s[i];
        }
    }
    
    // Push the last word if it exists
    if(!str.empty()) 
    {
        st.push(str);
    }

    string ans = "";
    while(!st.empty()) 
    {
        ans += st.top();
        st.pop();
        if(!st.empty()) 
        {
            ans += " ";
        }
    }

    return ans;
}

// Optimal - O(n), n = length of string
string reverseWords(string s)
{
    string temp = "";
    string ans = "";
    
    for (char ch : s) 
    {
        if (ch != ' ') 
        {
            temp += ch;
        } 
        else 
        {
            if (!temp.empty()) 
            {
                if (!ans.empty()) 
                {
                    ans = temp + " " + ans;
                } 
                else 
                {
                    ans = temp;
                }
                temp = "";
            }
        }
    }
    
    // Add the last word if it exists
    if (!temp.empty()) 
    {
        if (!ans.empty()) 
        {
            ans = temp + " " + ans;
        } 
        else 
        {
            ans = temp;
        }
    }
    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {
        string s = "Gyan Ranjan Kumar";
        cout<< "Before reversing words: " << endl;
        cout<< s << endl;
        cout<< "After reversing words: " << endl;
        cout<< reverseWords(s); 
    }

    return 0;
}