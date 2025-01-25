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

// Create a 1D-Array in 3 ways and print
// 1. Normal
// 2. Dynamically
// 3. STL Vector

void Normal(int n)
{
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i+1;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void Dynamically(int n)
{
    int* arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i+1;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void STLvector(int n)
{
    vector<int> arr;

    for(int i = 0; i < n; i++)
    {
        arr.push_back(i+1);
    }

    for(int i : arr)
    {
        cout << i << " ";
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
        int n = 5;

        Normal(n);
        cout << endl;

        Dynamically(n);
        cout << endl;

        STLvector(n);
    }

    return 0;
}