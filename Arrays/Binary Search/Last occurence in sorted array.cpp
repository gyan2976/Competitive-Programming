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
int solve(vector<int> &v, int n, int key) 
{
  int res = -1;
  for (int i = n - 1; i >= 0; i--) 
  {
    if (v[i] == key) 
    {
      res = i;
      break;
    }
  }
  return res;
}

// Optimal [Binary Search] O(logN)
int solve(vector<int> &v, int n, int key)
{
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(v[mid] == key)
        {
            ans = mid;
            low = mid + 1;  // Look right for last occuring
        }
        else if(key < v[mid])
        {
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
        int n = 7;
        vector <int> v = {3, 4, 13, 13, 13, 20, 40};
        int key = 13;
        int ans = solve(v, n, key);
        cout << ans << endl;

    }

    return 0;
}