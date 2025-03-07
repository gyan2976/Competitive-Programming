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
bool searchRotatedSorted(vector<int> &arr, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

// Optimal O(logN) 
bool searchRotatedSorted(vector<int> &arr, int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x)
        {
            return true;
        }
        
        if(arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(arr[low] <= arr[mid])   // Check left if sorted or not
        {
            if(arr[low] <= x && x <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else    // Check right if sorted or not
        {
            if(arr[mid] <= x && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
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
        vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
        int n = arr.size(), k = 3;
        bool ans = searchRotatedSorted(arr, n, k);
        cout << ans << endl;
    }

    return 0;
}