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

// 1. Brute Force O(n^3)
void LongestSubarrayK(int *arr, int n, int k)
{
    int longest = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int x = i; x <= j; ++x)
            {
                sum += arr[x];
            }

            if(sum == k)
            {
                longest = max(longest, j-i+1);
            }

        }
    }

    cout << "Longest subarray with sum k is: " << longest << endl;
}


// 2. Brute Force O(n^2)
void LongestSubarrayK(int *arr, int n, int k)
{
    int longest = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == k)
            {
                longest = max(longest, j-i+1);
            }

        }
    }

    cout << "Longest subarray with sum k is: " << longest << endl;
}

//3. Ordered Hashmap O(N*log(N))
void LongestSubarrayK(int *arr, int n, int k)
{
    map<int, int> mp;
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxLen = max(maxLen, i+1);
        }

        int rem = sum - k;
        if(mp.find(sum) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }

        if(mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    cout << "Longest subarray with sum k is: " << maxLen << endl;
}

//4. Optimal - Two Pointers O(N)
void LongestSubarrayK(int *arr, int n, int k)
{
    int left = 0, right = 0;
    int sum = 0;
    int maxLen = 0;

     while (right < n) 
    {
        // Expand the window by adding the rightmost element
        sum += arr[right];

        // Shrink the window from the left until the sum is <= k
        while (left <= right && sum > k) 
        {
            sum -= arr[left];
            left++;
        }

        // If the current window's sum equals k, update maxLen
        if (sum == k) 
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move the right pointer to expand the window
        right++;
    }

    cout << "Longest subarray with sum k is: " << maxLen << endl;
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
        int n = 5;
        int arr[] = {2, 3, 5, 1, 9};
        int k = 10;
        LongestSubarrayK(arr, n, k);
    }

    return 0;
}
