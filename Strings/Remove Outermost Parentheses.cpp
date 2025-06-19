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

// Optimal - O(n)
string removeOuterParentheses(string s)
{
    int count = 0;
    string output = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            if(count != 0)
            {
                output.push_back(s[i]);
            }
            count++;
        }
        else
        {
            if(count != 1)
            {
                output.push_back(s[i]);
            }
            count--;
        }
    }
    return output;
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
        string s = "(()())(())";
        string ans = removeOuterParentheses(s);
        cout << ans << endl; 
    }

    return 0;
}