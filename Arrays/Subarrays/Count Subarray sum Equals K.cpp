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
int subarraySumK(int *arr, int n, int k)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == k)
            {
                count += 1;
            }
        }
    }

    return count;
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
        int n = 4;
        int arr[] = {3, 1, 2, 4};
        int k = 6;
        int ans = subarraySumK(arr, n, k);
        cout << "Total subarrays equals to sum K is: " << ans << endl;
    }

    return 0;
}