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
using namespace std;

void func(int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << "Square of " << i << ": " << i * i << endl;
        cout << "Cube of " << i << ": " << i * i * i << endl;
    }
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
        int n = 3;
        func(n);
    }

    return 0;
}
