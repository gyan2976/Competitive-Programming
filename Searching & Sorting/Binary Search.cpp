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

int binarySearch(int *arr, int low, int high, int x)
{
    sort(arr, arr+high);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] > x)
        {
            return binarySearch(arr, low, mid-1, x);
        }
        else
        {
            return binarySearch(arr, mid+1, high, x);
        }

    }

    return -1;
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

        int x = 87;

        int result = binarySearch(arr, 0, n-1, x);
        cout << result << endl;

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }


    }

    return 0;
}