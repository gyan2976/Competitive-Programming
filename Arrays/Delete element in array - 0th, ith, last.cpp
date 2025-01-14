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

void zerothPosition(int *arr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    for(int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " ";
    }
}

void ithPosition(int *arr, int n, int ith)
{

    for(int i = ith; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    for(int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " ";
    }
}

void lastPosition(int *arr, int n)
{

    arr[n-1] = '\0';

    for(int i = 0; i < n-1; i++)
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
        int arr[5] = {1, 2, 3, 4, 5};
        int n = sizeof(arr) / sizeof(arr[0]);

        zerothPosition(arr, n);

        int ith = 2;
        ithPosition(arr, n, ith);

        lastPosition(arr, n);

    }

    return 0;
}