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

void LeftrotateOnePosition(int *arr, int n)
{
    // Left rotate by one position
    int temp = arr[0];
    for(int i = 0; i < n; i++)
    {
        arr[i] = arr[i+1];
    }

    arr[n-1] = temp;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void RightrotateOnePosition(int *arr, int n)
{
    // Right rotate by one position
    int temp = arr[n-1];
    for(int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = temp;

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

        LeftrotateOnePosition(arr, n);
       
        RightrotateOnePosition(arr, n);
    }

    return 0;
}