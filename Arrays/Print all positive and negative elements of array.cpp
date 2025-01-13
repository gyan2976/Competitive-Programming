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
    cout << "Size: " << n << endl;

    int pos[n] = {0};
    int neg[n] = {0};

    int pidx = 0, nidx = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            pos[pidx++] = arr[i];
        }
        else
        {
            neg[nidx++] = arr[i];
        }
    }

    cout << "Positive: ";
    for(int i = 0; i < pidx; i++)
    {
        cout << pos[i] << " ";
    }

    cout << endl;

    cout << "Negative: ";
    for(int i = 0; i < nidx; i++)
    {
        cout << neg[i] << " ";
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
        int arr[] = {1 , -25, 56, -97, 88, -35};
        int n = sizeof(arr) / sizeof(arr[0]);
        func(arr, n);
    }

    return 0;
}