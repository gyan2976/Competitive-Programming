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

// 1. Brute Force
void numberAppearsNby2(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        int j = 0;
        while(j < n)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
            j++;
        }

        if(count > (n/2))
        {
            cout << arr[i] << endl;
            break;
        }
    }
}

// 2. Hashmap
void numberAppearsNby2(int *arr, int n)
{
    map<int, int> mpp;

    for (int i = 0; i < n; i++) 
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp) 
    {
        if (it.second > (n / 2)) 
        {
            cout << it.first << endl;;
        }
    }
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
        int arr[] = {2, 2, 1, 1, 1, 2, 2};

        numberAppearsNby2(arr, n);
    }

    return 0;
}