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

void zerothPosition(int *arr, int n, int x)
{
    for(int i = n; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = x;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void ithPosition(int *arr, int n, int x, int ith)
{

    for(int i = n; i > ith; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[ith] = x;


    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void lastPosition(int *arr, int n, int x)
{

    arr[n-1] = x;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
        int arr[6] = {1, 2, 3, 4, 5};
        int n = sizeof(arr) / sizeof(arr[0]);

        int x = 56;

        zerothPosition(arr, n, x);

        int ith = 2;
        ithPosition(arr, n, x, ith);

        lastPosition(arr, n, x);

    }

    return 0;
}