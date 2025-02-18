#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string replaceCharacter(string &str, char oldChar, char newChar)
{
    // int n = strlen(str);
    int n = str.length();

    for(int i = 0; i < n; i++)
    {
        if(str[i] == oldChar)
        {
            str[i] = newChar;
        }
    }
    return str;
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
        string str;
        cin >> str;

        char oldChar, newChar;
        cin >> oldChar >> newChar;

        string ans = replaceCharacter(str, oldChar, newChar);
        cout << ans << endl;
    }

    return 0;
}