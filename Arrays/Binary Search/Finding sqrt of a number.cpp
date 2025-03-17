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
int floorSqrt(int n)
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        long long value = i * i;
        if(value <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

// Optimal O(logN)
int floorSqrt(int n)
{
    int ans = sqrt(n);
    return ans;
}

// Optimal - Binary Search O(logN)
int floorSqrt(int n)
{
    int low = 0;
    int high  = n;
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long value = mid * mid;
        if(value <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
        int n = 28;
        int ans = floorSqrt(n);
        cout << ans << endl;
    }

    return 0;
}