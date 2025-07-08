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
// Time Complexity: O(n^3)
// Space Complexity: O(1)
bool checkPalindrome(string str)
{
    int start = 0;
    int end = str.length()-1;
    while(start <= end)
    {
        if(str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s)
{
    int n = s.length();
    string longest = "";
    int maxLen = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            string sub = s.substr(i, j - i + 1);
            if(checkPalindrome(sub) && sub.length() > maxLen)
            {
                longest = sub;
                maxLen = sub.length();
            }
        }
    }
    return longest;
}

// Optimal - O(n^2)
string longestPalindrome(const string& s) 
{
    if (s.empty()) return "";
    
    int n = s.length();
    int start = 0, maxLength = 1;

    for (int i = 0; i < n; i++) 
    {
        // Check for odd length palindromes centered at i
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) 
        {
            if (right - left + 1 > maxLength) 
            {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }

        // Check for even length palindromes centered between i and i+1
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) 
        {
            if (right - left + 1 > maxLength) 
            {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
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
        string s = "babad";
        // string s = "cbbd";
        string ans = longestPalindrome(s);
        cout << ans << endl;

    }

    return 0;
}