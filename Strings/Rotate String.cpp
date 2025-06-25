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
bool rotateString(string s, string goal) {
    int n = s.size();
    if (n != goal.size()) return false;
    if (n == 0) return true;

    for (int k = 0; k < n; ++k) {
        if (s[k] == goal[0]) {
            bool match = true;
            for (int i = 0; i < n; ++i) {
                if (s[(k + i) % n] != goal[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    return false;
}


// Solution 1
bool rotateString(string s, string goal) 
{
    int len = s.length();
    if (len != goal.length()) return false;
    for (int i = 0; i < len; i++)
    {
        string sub = s.substr(i) + s.substr(0, i); // Rotate left by i positions
        if (sub == goal)
        {
            return true;
        }
    }
    return false;
}

// Solution 2
bool rotateStringChecking(string A, string B, int rotation)
{
    for(int i = 0; i < A.length(); i++) 
    {
        if(A[i] != B[(i+rotation)%B.length()]) 
        {
            return false;
        }
    }
    return true;
}

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length()) 
    {
        return false;
    }

    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(rotateStringChecking(s, goal, i)) 
        {
            return true;
        }
    }
    return false;
}

// Solution 3
bool rotateString(string s, string goal) 
{
    if(s.size() != goal.size()) return false;
    string check = s+s;
    return check.find(goal) != string::npos;
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
        // string s = "abcde", goal = "cdeab";
        string s = "abcde", goal = "eabcd";
        // string s = "abcde", goal = "abced"
        bool ans = rotateString(s, goal);
        cout << ans << endl;
    }

    return 0;
}