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

// Brute Force - O(N * (sum(weights[]) - max(weights[]) + 1))
int capacity(vector<int> &arr, int cap)
{
    int load = 0;
    int totalDays = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(load + arr[i] > cap)
        {
            totalDays++;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return totalDays;
}

int shipWithinDays(vector<int>& weights, int days) 
{
    int minimumCapacity = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    for(int i = minimumCapacity; i <= sum; i++)
    {
        if(capacity(weights, i) <= days)
        {
            return i;
        }
    }
    return -1;
}

// Optimal - O(N * log(sum(weights[]) - max(weights[]) + 1))
int capacity(vector<int> &arr, int cap)
{
    int load = 0;
    int totalDays = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(load + arr[i] > cap)
        {
            totalDays++;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return totalDays;
}

int shipWithinDays(vector<int>& weights, int days) 
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(capacity(weights, mid) <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
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
        vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int d = 5;
        int ans = shipWithinDays(weights, d);
        cout << ans << endl;
    }

    return 0;
}