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

// Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
int myAtoi(string s)
{
    int len = s.length();

    if(len == 0)
    {
        return 0;
    }
    int i = 0;

    // Leading Whitespace
    while(i < len && s[i] == ' ')
    {
        i++;
    }

    // Sign - and +
    int sign = 1;
    if(s[i] == '+' || s[i] == '-') 
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    long result = 0;
    while(i < len && isdigit(s[i])) 
    {
        int digit = s[i] - '0';
        result = result * 10 + digit;
        
        // Check for overflow
        if(sign == 1 && result > INT_MAX) 
        {
            return INT_MAX;
        }
        if(sign == -1 && -result < INT_MIN) 
        {
            return INT_MIN;
        }
        
        i++;
    }

    return sign * result;
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
        string s = "42";
        string s = " -042";
        string s = "1337c0d3";
        string s = "0-1";
        string s = "words and 987";
        int ans = myAtoi(s);
        cout << ans << endl;

    }

    return 0;
}