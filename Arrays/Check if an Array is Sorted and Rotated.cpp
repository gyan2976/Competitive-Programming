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

void checkSortedRotated(int *arr, int n)
{
   int count = 0;
   for(int i = 0; i < n; i++)
   {
        if(arr[i] > arr[i+1])
        {
            count++;
        }
   }

   if(arr[n-1] > arr[0])
   {
        count++;
   }

   if(count <= 1)
   {
        cout << "Yes! The Array is Sorted and Rotated" << endl;
   }
   else
   {
        cout << "No! The Array is not Sorted and Rotated" << endl;
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

        checkSortedRotated(arr, n);
    }

    return 0;
}