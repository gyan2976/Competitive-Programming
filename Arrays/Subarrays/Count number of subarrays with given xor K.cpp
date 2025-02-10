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
int subarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int XOR = 0;
            for(int y = i; y <= j; y++)
            {
                XOR = XOR ^ arr[y];
            }

            if(XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

// Better O(n^2)
int subarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int XOR = 0;
        for(int j = i; j < n; j++)
        {
            XOR = XOR ^ arr[j];

            if(XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

// Optimal - Hashing O(n)
int subarraysWithXorK(vector<int> &arr, int k)
{
    int n = arr.size();
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ arr[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
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
        vector<int> a = {4, 2, 2, 6, 4};
        int k = 6;
        int ans = subarraysWithXorK(a, k);
        cout << "The number of subarrays with XOR k is: " << ans << endl;
    }

    return 0;
}