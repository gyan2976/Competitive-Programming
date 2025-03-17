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
long long func(int x, int exp)
{
    long long  ans = 1;
    long long base = x;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int nthRoot(int n, int number)
{
    for(int i = 1; i <= number; i++)
    {
        long long val = func(i, n);
        if(val == number * 1ll)
        {
            return i;
        }
        else if(val > number * 1ll)
        {
            break;
        }
    }
    return -1;
}

// Binary Search O(logN)
//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int number)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > number) return 2;
    }
    if (ans == number) return 1;
    return 0;
}

int nthRoot(int n, int number)
{
    int low = 1;
    int high = number;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, number);
        if (midN == 1) 
        {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
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
        int n = 3, number = 27;
        int ans = nthRoot(n, number);
        cout << ans << endl;
    }

    return 0;
}