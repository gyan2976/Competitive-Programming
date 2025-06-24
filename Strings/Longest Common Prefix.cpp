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
string longestCommonPrefix(vector<string> &strs) 
{
    if(strs.empty()) return "";
    int n = strs.size();
    string prefix = strs[0];
    for (int i = 1; i < n; i++) 
    {
        while (strs[i].find(prefix) != 0) 
        {
            prefix = prefix.substr(0, prefix.length() - 1);
            if(prefix.empty())
            {
                return "";
            }
        }
    }
    return prefix;
}

// Solution 2
string longestCommonPrefix(vector<string> &strs)
{
    if(strs.empty()) return "";
        
    sort(strs.begin(), strs.end());

    string ans = "";
    string first = strs[0], last = strs[strs.size()-1];
    int min_len = min(first.size(), last.size());
    for(int i = 0; i < n; i++)
    {
        if(first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
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
        vector<string> strs = {"flowers", "flow", "fly", "flight"};
        string ans = longestCommonPrefix(strs);
        cout << ans << endl;

    }

    return 0;
}