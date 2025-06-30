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
int maxDepth(string s)
{
    int count = 0;
    int maximum = INT_MIN;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            count++;
            maximum = max(maximum, count);
        }
        else if (s[i] == ')')
        {
            count--;
            
        }
    }
    return maximum;
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
        string s = "(1+(2*3)+((8)/4))+1";
        // string s = "(1)+((2))+(((3)))";
        // string s = "()(())((()()))";
        int ans = maxDepth(s);
        cout << ans << endl;

    }

    return 0;
}