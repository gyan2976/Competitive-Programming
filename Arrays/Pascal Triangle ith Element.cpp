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

// Question: Given a pascal triangle, find the element of given row and i-th element
// Example: row = 5, i-th_ele = 3
// Answer: 6

void pascalTriangle(int n, int r)
{
    // Optimize the formula nCr = n! / (r! * (n-r)!)
    long long int res = 1;
    for(int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }

    cout << "Element at " << n << "th row and " << r << "th element is: " << res;
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
        int n, ith;
        cin >> n >> ith;

        pascalTriangle(n-1, ith-1);
    }

    return 0;
}