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

// Brute Force - O(logN)
int findKthPositive(vector<int>& arr, int k) 
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

// Optimal - O(N)
int findKthPositive(vector<int>& arr, int k) 
{
    int low = 0;
    int high = arr.size()-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high + 1 + k;   // (or return low + k)
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
        vector<int> vec = {4, 7, 9, 10};
        int k = 4;
        int ans = findKthPositive(vec, k);
        cout << ans << endl;
    }

    return 0;
}