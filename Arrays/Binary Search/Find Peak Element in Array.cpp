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

// Condition of Peak elemnet: arr[i-1] < arr[i] > arr[i+1]
// A array can have multiple peak elements
// take -infinity on both ends of array

// Brute Force O(N)
// int findPeakElement(vector<int> &arr)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         //Checking for the peak:
//         if ((i == 0 || arr[i - 1] < arr[i])
//                 && (i == n - 1 || arr[i] > arr[i + 1])) {
//             return i; //index or we can return arr[i]
//         }
//     }
//     return -1;
// }

// Binary Search O(logN)
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    if(n == 1) return 0;                   // Single element
    if(arr[0] > arr[1]) return 0;          // Check first
    if(arr[n-1] > arr[n-2]) return n-1;    // Check last

    int low = 1, high = n-2;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // If mid is peak
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) 
        {
            return mid;
        }
        else if(arr[mid] > arr[mid-1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
        int ans = findPeakElement(arr);
        cout << ans << endl;
    }

    return 0;
}