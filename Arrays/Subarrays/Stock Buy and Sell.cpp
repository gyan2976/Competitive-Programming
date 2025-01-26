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

// O(n^2)
void stockBuyandSell(int *arr, int n) 
{
    int maxPro = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                maxPro = max(maxPro, arr[j] - arr[i]);
            }
        }
    }

    cout << "Maximum Profit: " << maxPro << endl;
}

// Optimal O(n)
void stockBuyandSell(int *arr, int n) 
{
    int maxPro = 0;
    int minPrice = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    cout << "Maximum Profit: " << maxPro << endl;
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
        int arr[] = {7, 1, 5, 3, 6, 4};

        stockBuyandSell(arr, n);
    }

    return 0;
}