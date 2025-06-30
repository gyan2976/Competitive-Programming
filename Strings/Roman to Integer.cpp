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
int romanToInt(string s)
{
    int res = 0;
    unordered_map<int, int> mp;
    mp = {{'I', 1},
          {'V', 5},
          {'X', 10}, 
          {'L', 50},
          {'C', 100},
          {'D', 500},
          {'M', 1000}};

    for(int i = 0; i < s.size()-1; i++)
    {
        if(mp[s[i]] < mp[s[i+1]])
        {
            res -= mp[s[i]];
        }
        else
        {
            res += mp[s[i]];
        }
    }
    return res + mp[s[s.size() - 1]];
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
        string s = "III";
        // string s = "LVIII";
        // string s = "MCMXCIV";
        int ans = romanToInt(s);
        cout << ans << endl;

    }

    return 0;
}