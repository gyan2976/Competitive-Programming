#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype> 
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Brute Force O(N)
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int minimum = INT_MAX;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < minimum)
        {
            minimum = arr[i];
            index = i;
        }
    }
    return index;
}

// Binary Search O(logN)
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int minimum = INT_MAX;
    int index = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        
        // sorted case (0 to n-1)
        if(arr[low] <= arr[high])
        {
            if(arr[low] < minimum)
            {
                index = low;
                minimum = arr[low];
            }
            break;
        }

        // look left (0 to mid)
        if(arr[low] <= arr[mid])
        {
            if(arr[low] < minimum)
            {
                minimum = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else   // look right (mid to n-1)
        {
            if(arr[mid] < minimum)
            {
                minimum = arr[mid];
                index = mid;
            }

            high = mid - 1;
        }
    }
    return index;
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
        vector<int> arr = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
        int ans = findKRotation(arr);
        cout << ans << endl;
    }

    return 0;
}