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

//              Pascal Triangle
//                      1
//                  1       1
//              1       2       1
//          1       3       3      1
//      1       4       6       4     1
//  1       5       10      10     5      1

// Question: Print nth row of a Pascal Triangle
// Answer: n = 5 [1 5 10 10 5 1]

int nCr(int n, int r)
{
    long long res = 1;
    for(int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }

    return res;
}

void nthRowPascalTriangle(int n)
{
    for(int c = 1; c <= n; c++)
    {
        cout << nCr(n-1, c-1) << " ";
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
        int n;
        cin >> n;

        nthRowPascalTriangle(n);
    }

    return 0;
}