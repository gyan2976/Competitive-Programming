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

void intersectionOfTwoArrays(int *arr1, int m, int *arr2, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                arr2[j] = INT_MIN;
                break;
            }
        }
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
        int m;
        cin >> m;
        int arr1[m];
        for(int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }

        int n;
        cin >> n;
        int arr2[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        intersectionOfTwoArrays(arr1, m, arr2, n);

    }

    return 0;
}