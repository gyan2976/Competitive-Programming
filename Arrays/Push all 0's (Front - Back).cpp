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

void pushZeros(int *arr, int n)
{
    int start = 0;
    int end = n-1;
    int index = 0;
    int temp[n];

    while(start <= end)
    {
        if(arr[start] != 0)
        {
            temp[index++] = arr[start];
        }
        start++;
    }

    start = 0;
    while(start <= end)
    {
        if(arr[start] == 0)
        {
            temp[index++] = arr[start];
        }
        start++;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

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
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        pushZeros(arr, n);

    }

    return 0;
}
