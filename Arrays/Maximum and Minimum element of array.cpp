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

void func(int *arr, int n)
{
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }

        if(arr[i] < mini)
        {
            mini = arr[i];
        }
    }

    cout << "Maximum: " << maxi << endl;
    cout << "Minimum: " << mini << endl;
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
        int arr[] = {1, -89, -65, 78, 49, -27, 91, -53, -37, 81};
        int n = sizeof(arr) / sizeof(arr[0]);
        func(arr, n);

        sort(arr, arr+n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

    }

    return 0;
}
