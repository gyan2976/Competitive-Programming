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
// Time - O(n)
// Space - O(1)
string reverseWords(string s)
{
    reverse(s.begin(), s.end());

    cout << "GGG: " << s << endl; // Output: GGG: eulb si yks eht

    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n) 
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ') 
        {
            s[right++] = s[i++];
        }

        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
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
        string s = "the sky is blue";  // Output: "blue is sky the"
        string s = "  hello world  ";  // Output: "world hello"
        string s = "a good   example"; // Output: "example good a"
        string ans = reverseWords(s);
        cout << ans << endl;

    }

    return 0;
}