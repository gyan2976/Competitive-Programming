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
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    }

    return 0;
}
