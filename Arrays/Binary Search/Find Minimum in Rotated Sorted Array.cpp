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
int findMin(vector<int> &arr)
{
    int n = arr.size();
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }
    return minimum;
}

// Optimal 1 O(logN)
int findMin(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid])    // Check left half
        {
            ans = min(ans, arr[low]);
            low = mid + 1;  // Eliminate left half
        }
        else    // Look right half
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Optimal 2 O(logN)
int findMin(vector<int> &arr)
{
    
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // If array is already sorted no need to search
        if (arr[low] <= arr[high]) 
        {
            ans = min(ans, arr[low]);
            break;
        }

        if(arr[low] <= arr[mid])    // Check left half
        {
            ans = min(ans, arr[low]);
            low = mid + 1;  // Eliminate left half
        }
        else    // Look right half
        {
            ans = min(ans, arr[mid]);
            high = mid - 1; // Eliminate right half
        }
    }
    return ans;

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
        vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
        int ans = findMin(arr);
        cout << "The minimum element is: " << ans << "\n";
    }

    return 0;
}