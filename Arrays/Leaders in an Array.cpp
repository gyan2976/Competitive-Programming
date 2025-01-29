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

void leadersArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = i+1; j <= n; j++)
        {
            if(arr[i] < arr[j])
            {
                count++;
            }
        }
        if(count <= 1)
        {
            cout << arr[i] << " ";
        }

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

        leadersArray(arr, n);
        cout << endl;
    }

    return 0;
}