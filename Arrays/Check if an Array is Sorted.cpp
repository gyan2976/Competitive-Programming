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

void checkSortedArray(int *arr, int n)
{
   bool isSorted = true;
   for(int i = 0; i < n; i++)
   {
        if(arr[i] < arr[i+1])
        {
            isSorted = false;
            break;
        }
   }

   if(isSorted)
   {
        cout << "Yes" << endl;
   }
   else
   {
        cout << "No" << endl;
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

        checkSortedArray(arr, n);
    }

    return 0;
}