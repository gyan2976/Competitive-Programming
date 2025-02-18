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
string trimSpaces(const string& str)
{
    int n = str.length();
    string result;

    for(int i = 0; i < n; i++)
    {
        if(str[i] != ' ')
        {
            result += str[i];
        }
    }

    return result;
}

// Solution 2 - Character Array
void trimSpaces(char input[]) {
    int i = 0, j = 0;
    while (input[i]) 
    {
        if (input[i] != ' ') 
        {
            input[j++] = input[i];
        }

        i++;
    }

    input[j] = '\0';
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
        // cin.ignore() or cin.get()
        cin.ignore();

        string str;
        getline(cin, str);

        // char str[100];
        // cin.getline(str, 100);

        cout << "Before: " << str << endl;

        string ans = trimSpaces(str);
        cout << "After: " << ans << endl;
    }

    return 0;
}