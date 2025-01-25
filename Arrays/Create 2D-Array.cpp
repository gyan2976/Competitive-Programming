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

// Create a 2D-Array in 3 ways and print
// 1. Normal
// 2. Dynamically
// 3. STL Vector

void Normal(int n)
{
    int m = n;
    int arr[m][n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = i+1;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Dynamically(int n)
{
    int m = n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = i * n + j;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void STLvector(int n)
{
    int m = n;
    vector<vector<int>> arr(n, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = j * m + i;
            cout << arr[i][j] << " ";
        }
        cout << endl;
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
        int n = 3;

        Normal(n);
        cout << endl;

        Dynamically(n);
        cout << endl;

        STLvector(n);
    }

    return 0;
}