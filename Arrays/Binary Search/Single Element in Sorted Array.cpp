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
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    // Solution 1
    if(n == 1)
    {
        return arr[0];
    }

    // Check for first and last element
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            if(arr[i] != arr[i+1])
            {
                return arr[i];
            }
        }
        else if(i == n-1)
        {
            if(arr[i] != arr[i-1])
            {
                return arr[i];
            }
        }
        else 
        {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
            {
                return arr[i];
            }
        }
    }

    // Solution 2
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1])
        {
            return arr[i];
        }
    }
    
    return -1;
}

// Brute Force - Hashmap
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it: mp)
    {
        if(it.second <= 1)
        {
            return it.first;
        }
    }
    return -1;
}

// Brute Force - XOR O(N)
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Binary Search O(logN)
int singleNonDuplicate(vector<int> &arr)
{
    // Discussion, if my mid is at even index or odd index
    // (even, odd) = standing at left half (element is on the right half)
    // (odd, even) = standing at right half (element is on the left half)
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // If mid is unique
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) 
        {
            return arr[mid];
        }
        // which part is needed to eliminate
        if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1]))
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
        vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
        int ans = singleNonDuplicate(arr);
        cout << ans << endl;
    }

    return 0;
}