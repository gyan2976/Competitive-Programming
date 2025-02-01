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

// Brute Force - For Loops O(n^2)
int subarraySumZero(vector<int> &arr, int n)
{
    int longest = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == 0)
            {
                longest = max(longest, j-i+1);
            }
        }
    }

    return longest;
}

// Brute Force - Hashmap O(n^2)
int subarraySumZero(vector<int> &arr, int n)
{
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
        {
            maxLen = i+1;
        }
        else if(mp.find(sum) != mp.end())
        {
            maxLen = max(maxLen, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return maxLen;
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
        int n = 6;
        vector<int> arr = {9, -3, 3, -1, 6, -5};
        int x = subarraySumZero(arr, n);
        cout << "Length of the longest subarray with sum Zero: " << x << endl;
    }

    return 0;
}