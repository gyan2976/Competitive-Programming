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

void sort012(int *arr, int n)
{
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            swap(arr[index++], arr[i]);
        }
    }

    for(int i = index; i < n; i++)
    {
        if(arr[i] == 1)
        {
            swap(arr[index++], arr[i]);
        }
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

        sort012(arr, n);

        delete[] arr;

    }

    return 0;
}
