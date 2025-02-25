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

// Brute Force O(n)
int lowerBound(vector<int> &arr, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= x)
        {
            return i;
        }
    }

    return n;
}

// Binary Search O(logN)
int lowerBound(vector<int> &arr, int n, int x)
{
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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
        vector<int> arr = {3, 5, 8, 15, 19};
        int n = 5, x = 9;
        int ind = lowerBound(arr, n, x);
        cout << "The lower bound is the index: " << ind << "\n";        
    }

    return 0;
}