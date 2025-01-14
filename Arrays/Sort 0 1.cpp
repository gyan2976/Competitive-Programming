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

void sort01(int *arr, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            count++;
            arr[i] = 0;
        }
    }

    while(count <= n)
    {
        arr[count++] = 1;
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
        int n, sum;
        cin >> n >> sum;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort01(arr, n);

    }

    return 0;
}
