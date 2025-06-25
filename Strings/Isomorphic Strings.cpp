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

// Solution 1
// Time Complexity: O(n²)
// Space Complexity: O(n)
bool isIsomorphic(string s, string t) 
{
    if (s.length() != t.length()) 
    {
        return false;
    }
    
    unordered_map<char, char> charMap;

    for (int i = 0; i < s.length(); ++i) 
    {
        char sc = s[i];
        char tc = t[i];

        if (charMap.count(sc)) 
        {
            if (charMap[sc] != tc) 
            {
                return false;
            }
        } 
        else 
        {
            for (auto& pair : charMap) 
            {
                if (pair.second == tc) 
                {
                    return false;
                }
            }
            charMap[sc] = tc;
        }
    }

    return true;     
}

// Solution 2
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.length(); ++i) 
    {
        char char_s = s[i];
        char char_t = t[i];

        if (s_to_t.find(char_s) != s_to_t.end()) 
        {
            if (s_to_t[char_s] != char_t) 
            {
                return false;
            }
        } 
        else 
        {
            s_to_t[char_s] = char_t;
        }

        if (t_to_s.find(char_t) != t_to_s.end()) 
        {
            if (t_to_s[char_t] != char_s) 
            {
                return false;
            }
        } 
        else 
        {
            t_to_s[char_t] = char_s;
        }
    }

    return true;
}

// Solution 3
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isIsomorphic(string s, string t)
{
    if(s.size() != t.size()) return false;

    int s_map[256] = {0}; // Assuming ASCII characters
    int t_map[256] = {0};
    
    for (int i = 0; i < s.length(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        if (s_map[char_s] != t_map[char_t]) {
            return false;
        }

        s_map[char_s] = i + 1; // Using i+1 to avoid default 0
        t_map[char_t] = i + 1;
    }

    return true;
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
        string s = "egg", t = "add";
        bool ans = isIsomorphic(s, t);
        cout << (ans ? "true" : "false") << endl;
    }

    return 0;
}