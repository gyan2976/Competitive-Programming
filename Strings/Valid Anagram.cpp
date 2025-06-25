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
// Sorting - Time: O(nlog(n) + mlog(m)), Space: O(1)
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Solution 2
// Hash Map - Time: O(n+m), Space: O(k) (k = unique chars)
bool isAnagram(string s, string t) 
{
    unordered_map<char, int> count;
    
    // Count the frequency of characters in string s
    for (auto x : s) {
        count[x]++;
    }
    
    // Decrement the frequency of characters in string t
    for (auto x : t) {
        count[x]--;
    }
    
    // Check if any character has non-zero frequency
    for (auto x : count) {
        if (x.second != 0) {
            return false;
        }
    }
    
    return true;
}

// Solution 3
// Fixed Array - Time: O(n+m), Space: O(1)
bool isAnagram(string s, string t) 
{
    int count[26] = {0};
    
    // Count the frequency of characters in string s
    for (char x : s) {
        count[x - 'a']++;
    }
    
    // Decrement the frequency of characters in string t
    for (char x : t) {
        count[x - 'a']--;
    }
    
    // Check if any character has non-zero frequency
    for (int val : count) {
        if (val != 0) {
            return false;
        }
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
        string s = "anagram", t = "nagaram";
        cout << (isAnagram(s, t) ? true : false) << endl;
    }

    return 0;
}