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

int removeDuplicates(int *arr, int n)
{
    int j = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[j-1])
        {
            arr[j] = arr[i];
            j++;
        }
    }

   return j;

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

        sort(arr, arr+n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;

        n = removeDuplicates(arr, n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}