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

string largestOddNumber(string num)
{
    for(int i = num.length()-1; i >= 0; i--)
    {
        if((num[i] - '0') % 2 != 0)
        {
            return num.substr(0, i+1);
        }
    }
    return "";
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
        string num = "35427";
        string ans = largestOddNumber(num);
        cout << ans << endl;

    }

    return 0;
}