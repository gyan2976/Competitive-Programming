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

// Brute Force - O(NlogN) + O(N *(max(stalls[])-min(stalls[])))
bool canBePossible(vector<int> &arr, int minDistance, int cows)
{
    int placeCow = 1;
    int n = arr.size();
    int lastPlaced = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] - lastPlaced >= minDistance)
        {
            placeCow++;
            lastPlaced = arr[i];
        }
        if(placeCow >= cows)
        {
            return true;
        }
    }
    return false;
}

int aggresiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int range = stalls[n-1] - stalls[0];
    for(int i = 1; i <= range; i++)
    {
        if(canBePossible(stalls, i, k) == false)
        {
            return (i-1);
        }
    }
    return range;
}

// Optimal - O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
bool canBePossible(vector<int> &arr, int minDistance, int cows)
{
    int placeCow = 1;
    int n = arr.size();
    int lastPlaced = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] - lastPlaced >= minDistance)
        {
            placeCow++;
            lastPlaced = arr[i];
        }
        if(placeCow >= cows)
        {
            return true;
        }
    }
    return false;
}

int aggresiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(canBePossible(stalls, mid, k) == false)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
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
        vector<int> stalls = {0, 3, 4, 7, 10, 9};
        int k = 4;
        int ans = aggresiveCows(stalls, k);
        cout << ans << endl;
    }

    return 0;
}