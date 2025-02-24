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

// 1. Iterative
int binarySearch(int *arr, int low, int high, int target)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// 2. Recursive
int binarySearch(int *arr, int low, int high, int target)
{
    // Base Case
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid] > target)
    {
        return binarySearch(arr, low, mid-1, target);
    }

    return binarySearch(arr, mid+1, high, target);
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
        int n = 7;
        int arr[] = {1, 3, 5, 6 , 9, 11, 95};
        int target = 5;

        int ans = binarySearch(arr, 0, n-1, target);
        cout << ans << endl;
        
    }

    return 0;
}